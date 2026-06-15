/* Time Complexity O(n^2), Space Complexity just bases on the implementation of the sort algorithm,
and between O(logn) - O(n) */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int l = 0, r = len-1;
        int sum = 0;
        vector<vector<int>>res;
        //if (nums.size() == 0 || nums.size() < 3 || nums[0] > 0 || nums[nums.size()-1] < 0) return res;
        for (int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // remove the duplicate triplets
            /*Update for the two pointer*/
            l = i+1;
            r = len-1;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < len-1 && nums[l] == nums[l+1]) l++; // remove the duplicate triplets
                    l++;
                    while(r > 0 && nums[r] == nums[r-1]) r--; // remove the duplicate triplets
                    r--;
                }
            }
        }
        return res; 
    }
};
