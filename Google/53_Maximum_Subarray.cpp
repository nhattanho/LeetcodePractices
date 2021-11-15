/*
max of sum(0,i) at a[i] = a[i] + (sum(0,i-1) < 0 ? 0 : sum(0,i-1))
==> will update a[i] as the maximum sum from the left until position ith.
Pseudo code:
if(sum < 0) {
    sum = nums[i]; //=> current sume
    maxNum = max(maxNum, sum);
}else {
    sum += nums[i];
    nums[i] = max(nums[i], sum); //==> current sum
    maxNum = max(maxNum, nums[i]);
}
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            nums[i] = max(nums[i], sum);
            maxNum = max(maxNum, nums[i]);
        }
        return maxNum;
    }
};
