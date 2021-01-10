class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return 0;
        
        int sum = 0, res = 0;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                sum += nums[j];
                if(sum == k) res = max(res, j-i+1);
            }
            sum = 0;
        }
        
        return res;
    }
};

/*Reducing the time complexity to O(n)*/
/*
        k = 3

        [0]  [1]  [2]  [3]  [4]
         2   -1    5   -2    3

sum      2    1    6    4    7


0-3: 4 ==> 0-1 + 2-3 = 4
            1     3
        
4-3 = 1

+ calculation the sum => add into map<sum, position> ==> check if subtraction = sum - key exist in the map ==> find out the len of sub array
link reference: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/discuss/77793/O(n)-C%2B%2B-solution-using-unordered_map
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, maxL = 0;
        unordered_map<int, int> sumIndex;
        
        for(int i = 0; i < len; i++){
            sum += nums[i];
            if(sumIndex.count(sum) == 0) sumIndex[sum] = i; // just need to get the first position of sums having equal value
            // pos:         [0] [1] [2] [3] [4] [5] [6] [7] [8]
            // example:      1  -1   1   5  -2   3  -2  -2  -2
            //==> sumIndex:  1   0   1   6   4   7   5   3   1 ==> for sum = 1, just give the position 0
            
            if(sum == k) maxL = max(maxL, i+1);
            else if (sumIndex.count(sum - k) != 0){
                maxL = max(maxL, i - sumIndex[sum-k]);
            }
        }
        return maxL;
        
    }
};


// The wrong way: checking with an example: [1 1 0] k = 1
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0, maxL = 0;
        unordered_map<int, int> sumIndex;
        
        for(int i = 0; i < len; i++){
            sum += nums[i];
            if(sumIndex.count(sum) == 0) sumIndex[sum] = i;
            else {
                if(sum == k) {
                    sumIndex[sum] = i;
                    // maxL = max(maxL,i+1);
                }
            }
        }
        
        for(auto x: sumIndex){
            if(x.first == k) maxL = max(maxL, x.second+1);
            else if(sumIndex.count(x.first-k) != 0) maxL = max(maxL, x.second-sumIndex[x.first-k]);
        }
        
        return maxL;
        
    }
};
