/*
After sorting, example we have:
a0 a1 a2 a3 a4 ........ a(n-4) a(n-3) a(n-2) a(n-1) an
we want to find min(max-min) ==> increase min, and decrease max

if min = a0 ==> max need to move to a(n-3)
if min = a1 (move 1 time) ==> max need to move to a(n-2) (move 2 times)
if min = a2 (move 2 times) ==> max need to move to a(n-1) (move 1 times)
if min = a3 (move 3 times) ==> max no need to move <=> an
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int len = nums.size();
        if(len <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 0; i <= 3; i++){
            res = min(res, nums[len-1 - (3-i)] - nums[i]);
        }
        return res; 
    }
};
