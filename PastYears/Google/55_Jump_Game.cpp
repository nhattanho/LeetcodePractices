/*
We just focus on if we can reach the last index, so check the maximum
reached index we can have for each element. For example, at index i
the maximum reached index will be nums[i] + i. If there is exist a
reached index which >= nums.size() ==> can reach the lastest index.
However, since the element can be equal to 0, so there is a case that
all maximum reached index before the element 0 at ith could not >= latest index
==> at the element (i+1)th, there is no reached index that can reach the
latest index.
For example:
index:  0 1 2 3 4 5 
array: [3,2,1,0,4 6]
+ at index = 0 ==> max reached: 0+3 = 3
+ at index = 1 ==> max reached: 1+2 = 3
+ at index = 2 ==> max reached: 2+1 = 3
+ at index = 3 ==> max reached: 3+0 = 3
+ at index = 4 > max reached index so far
==> could not reach the index = 5
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > max_reach) return false;
            max_reach = max(max_reach, i+nums[i]);
            if(max_reach >= nums.size()-1) return true;
        }
        return true;
    }
};
