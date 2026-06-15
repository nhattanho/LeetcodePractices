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

class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++){
            int temp = nums[i] + nums[i-1];
            if(temp > nums[i])  nums[i] = temp;
            sum = Math.max(sum, nums[i]);
        }
        return sum;
    }
}
