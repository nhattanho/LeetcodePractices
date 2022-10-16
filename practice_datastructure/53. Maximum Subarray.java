class Solution {
    public int maxSubArray(int[] nums) {
        int sum  = 0, res = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            if(sum < nums[i]) sum = nums[i];
            res = Math.max(sum, res);
        }
        return res;
    }
}
