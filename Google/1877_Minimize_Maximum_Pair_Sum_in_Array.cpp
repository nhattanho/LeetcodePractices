/*
Example we have an array:
[amin, a1, a2, ....., amax]
==> sort will be neccessary for this problem
Then the pair we can have:
1. (amin + ai, amax + aj1, ...., ak + ah)  ==> max1 = max(amax + aj, ak + ah)
   (amin + ai, amax + aj2, ...., ak1 + ah1)
   (amin + ai, amax + aj3, ...., ak2 + ah2)
   ........................................
   
2. (amin + amax, ai + aj,...)             ==> max2 = max(amin + amax, ai + aj)
   (amin + amax, ai1 + aj1,...)
   (amin + amax, ai2 + aj2,...)
   
==> min(max1, max2) = max2 since max1 = amax + aj is always >= amax + amin or ai + aj
Also, if max1 = ak + ah mean ak + ah > amax + aj, then of course ak + ah >= max2
==> the min has to be max2.

In case of max2, we also have some sub cases:
amin+amax, a1+a2, a3+a4.... ==> max = max(amin+amax, a1+a2, a3+a4, ....) (1)
amin+amax, a1+a3, a2+a4,... ==> max = max(amin+amax, a1+a3, a2+a4, ....) (2)
amin+amax, a1+a3, a5+a6,... ==> max = max(amin+amax, a1+a3, a5+a6, ....) (3)

if ai + aj in 3 example cases always >= amin+amax, or max1,2,3 = ai + aj ==> we go back to the original requirement which
is find the minimum of maximum pairs from the array [a1, a2, ......] ==> do the same analysis

if max(1) is amin+amax, max(2) or max(3) is ai + aj and ai + aj >= amin+amax ==> result is amin+amax

if amin+amax is always greater than the other pairs ==> it has to be final result.

*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < len/2; i++){
            res = max(res, nums[i]+nums[len-1-i]);
        }
        return res;
    }
};
