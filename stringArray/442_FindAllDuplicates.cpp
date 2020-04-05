/* This problem has the same idea as Find All numbers disappeared
 * in an array, Time Complexity O(n), Space O(1)*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans;
        for(auto x: nums){
            if(nums[abs(x)-1] < 0) ans.push_back(abs(x));
            else nums[abs(x)-1] *= -1;
        }
        return ans;
    }
};
