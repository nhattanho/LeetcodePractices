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
            if(sumIndex.count(sum) == 0) sumIndex[sum] = i;
            
            if(sum == k) maxL = max(maxL, i+1);
            else if (sumIndex.count(sum - k) != 0){
                maxL = max(maxL, i - sumIndex[sum-k]);
            }
        }
        return maxL;
        
    }
};
