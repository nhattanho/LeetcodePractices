class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0) ;
        if(nums.size() < 3) 
            return nums.size()==1?nums[0]:max(nums[0], nums[1]);
        
        
        for(int i = 0; i < 2; i++)
            dp[i] = nums[i];
        
        for(int i = 2; i < nums.size(); i++){
            if(i == 2) dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            else dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};

/*Optimize space*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0) ;
        if(nums.size() < 3) 
            return nums.size()==1?nums[0]:max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            if(i == 2) nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
            else nums[i] = max(nums[i-2], nums[i-3]) + nums[i];
        }
        return max(nums[nums.size()-1], nums[nums.size()-2]);
    }
};

/*Another approach*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), 0) ;
        if(nums.size() < 3) 
            return nums.size()==1?nums[0]:max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            if(i == 2) nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
            else {
                int temp = max(nums[i-2], nums[i-3]) +nums[i];
                nums[i] = max(temp, nums[i-1]);
            }
        }
        return nums[nums.size()-1];
    }
};
