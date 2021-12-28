class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int sum = nums[l]+nums[r];
            if(sum == target) return {l+1, r+1};
            if(sum > target) r--;
            else l++;
        }
        return {0,0};
    }
};
