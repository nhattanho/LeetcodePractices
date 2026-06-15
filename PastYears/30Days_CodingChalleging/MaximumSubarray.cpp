/*Using DP solution with Time Complexity O(n^2) Space O(n^2)*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        //if(len == 0) return 0;
        vector<vector<int>>temp(len, vector<int>(len,0));
        int max1 = INT_MIN, pre_max = 0;
        for(int n = 1; n <= len; n++){
            for(int i = 0; i <= len-n; i++){
                pre_max = max1;
                int j = n+i-1;
                if(n == 1) temp[i][j] = nums[i];
                else temp[i][j] = temp[i][j-1] + temp[j][j];
                max1 = max(temp[i][j], pre_max);
            }
        }
        return max1;
    }
};

/*Optimizing DP solution with Time Complexity is O(n), and Space is O(n)
 * For example: -2 1 -3 4 -1 2 1 -5 4 by using extra space pre[i] to 
 * save the total sum of nums[i] and previous nums. Besides, if pre[i]
 * less than 0, it does nothing for increasing the sum, so we don't count it
 * by setting it equal 0. So we will have:
 * nums:     -2 1 -3 4 -1 2 1 -5 4 ==>
 * pre : <==> 0 1  0 4  3 5 6  1 4 
 * However, with this way, we have to deal with case
 * that having all negative number, because the value of all pre[i] are equal
 * 0. Fortunately, the max substring in array having all negative numbers is 
 * the max element in this array. Simulation as below:
 * nums:     -2 -3 -4 -1 -5 -6 (2) 
 * pre : <==> 0  0  0  0  0  0 (2) ==> max substring have to be -1*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), max1 = INT_MIN;;
        vector<int>pre(len,0);
        for(int i = 0; i < len; i++){
            pre[i] = max(nums[i] + (i == 0 ?0:pre[i-1]),0);
            max1 = max(pre[i],max1);
        }
        if(max1 == 0) return *max_element(nums.begin(), nums.end());
        return max1;
    }
};

/*Optimal Solution by using Kadane's Algorithm, Time Complexity O(n), Space O(1)*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = 0, max1 = INT_MIN;
        for(int i = 0; i < len; i++){
            sum +=  nums[i];
            if(sum > max1) max1 = sum;
            if(sum < 0) sum = 0;
        }
        return max1;
    }
};
