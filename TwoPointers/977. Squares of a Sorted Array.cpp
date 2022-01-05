class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size()-1;
        vector<int>res(nums.size(),0);/*space O(n) if take output into account*/
        int l = 0, r = nums.size()-1;
        while(l <= r){/*Time complexity O(n)*/
            if(nums[l]*nums[l] <= nums[r]*nums[r]) {
                res[len] = nums[r]*nums[r];
                r--;
            }
            else {
                res[len] = nums[l]*nums[l];
                l++;
            }
            len--;
        }
        return res;
    }
};
