class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 1) return nums[0];
        for(int i = 2; i < len; i++){
            if(i == 2) nums[i] += nums[0];
            else nums[i] = Math.max(nums[i]+nums[i-2], nums[i]+nums[i-3]);
        }
        return Math.max(nums[len-1], nums[len-2]);
    }
}
