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

/*Optimal Solution Time Complexity O(n), Space O(1)*/
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
