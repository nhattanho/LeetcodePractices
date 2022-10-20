class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if(size < 3) return size == 1? nums[0]: max(nums[0], nums[1]);
        
        nums[1] = max(nums[1], nums[0]);
        for(int i = 2; i < size; i++){
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        return nums[size-1];
    }
};
