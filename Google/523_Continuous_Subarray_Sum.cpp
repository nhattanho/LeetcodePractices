/*
Assume [a1 a2 a3 a4 a5 a6 a7 a8]
a1 % k = x ==> a1 = ka + x
Then:

a1 = ka + x1                (1)
a1+a2 = ka + x2             (2)
a1+a2+a3 = ka + x3          (3)
a1+a2+a3+a4 = ka + x4       (4)
a1+a2+a3+a4+a5 = ka + x5    (5)

if each sum % k = 0 
Or
if x5 = x3 ==> (5) - (3) = a4+a5 = ka will %k = 0
==> that is reason why to check if there is exist an contigous array whose sum % k = 0
==> we simply check:
1: if the sum % k = 0 directly
2: caculate the mod of each sum, if the mod has already exist ==> there is exist a subarray satisfied 

However, the thing is the subarray has at least 2 element. So for:
1: check the number element in current sub has to be > 1
2: need a map to save: (value of mod, position)
when value of mod exists, pos2-pos1 > 1
*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int,int>mod;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(i > 0 && sum%k == 0) return true;
            
            /*As default, the mod[value] will be set to 0
            then, to distinguish if the mod has been existed, 
            should avoid value = 0 for the second check ==> i+1
            Specifically, this covers edge case: [2 0 0 0] k = 3*/
            if(mod[sum%k] == 0) mod[sum%k] = i+1;
            else {
                if(i+1-mod[sum%k] > 1) return true;
            }
        }
        return false;
    }
};
