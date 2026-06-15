class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1; /*Space O(1)*/
        while(l<=r){ /*Time O(logn)*/
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
