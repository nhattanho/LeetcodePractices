class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Time and Space: 0(nlogn)
        int left = 0, right = nums.size()-1;
        int res = -1;
        while(left < right){
            if(nums[left]+nums[right] >= k) {
                right--;
            }
            else if (nums[left] + nums[right] < k) {
                res = max(nums[left]+nums[right], res);
                left++;
            }
        }
        return res;
    }
};
