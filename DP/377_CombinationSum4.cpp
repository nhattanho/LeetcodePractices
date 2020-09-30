/* Even though we use DP in this solution, the time complexity, however, is still O(N*N^(target/M),
with N is the length of nums, and M is the minimum value of given array */ 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<unsigned int> dp(target+1, 0);      
        return find(nums, target, dp);
    }
    
    int find(vector<int>nums, int target, vector<unsigned int>&dp){
        if(target == 0) return 1;
        if(dp[target] != 0) return dp[target];
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
            if(target >= nums[i]) count += find(nums, target-nums[i], dp);
            
        dp[target] = count;
        return dp[target];
    }
};

/* ==> Reduce previous solution */

class Solution {
public:
    unordered_map<int, int>dp;
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(dp.count(target)!= 0) return dp[target];
        int count = 0;
        for(auto x: nums){
            if(target >= x){
                count += combinationSum4(nums, target-x);
            }
        }
        dp[target] = count;
        return count;
        
    }
};

/* Optimal Solution with Time complexity O(M*N), with M is target and N is length of given array */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto x: nums){
                if(i >= x){
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }
};
