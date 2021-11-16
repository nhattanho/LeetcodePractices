/*
Example we have:
0 1 0 0 1 1 0
Then applying add/subtract 1 for each 0 and 1, we will have:

index 0   0                 sum = -1
index 1   0 1               sum = 0  
index 2   0 1 0             sum = -1
index 3   0 1 0 0           sum = -2
index 4   0 1 0 0 1         sum = -1
index 5   0 1 0 0 1 1       sum = 0
index 6   0 1 0 0 1 1 0     sum = -1
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int>m; //sum, pos
        
        // 0 => -1
        // 1 ==> +1
        //+ sum = 0 => get the len
        // check the prefix in map, existed ==> pos2-pos1 to get the len
        int res = 0, sum = 0;
        for (int i = 0; i < len; i++){
            sum += nums[i]==0?-1:1;
            
            if(sum == 0) res = max(res, i+1);
            
            /*Use value to check if key existed. Since, as default
            in map, all key will be set to have value = 0. If the special
            case s[-1] = i = 0, then next time even -1 appear in 2nd time,
            the value still be 0 ==> could not update the max len*/
            if (m[sum] == 0) m[sum] = i+1;
            else res = max(res, i+1-m[sum]);
        }
        return res;
    }
};

/*Or can use*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int>m; //sum, pos
        
        // 0 => -1
        // 1 ==> +1
        //+ sum = 0 => get the len
        // check the prefix in map, existed ==> pos2-pos1 to get the len
        int res = 0, sum = 0;
        for (int i = 0; i < len; i++){
            sum += nums[i]==0?-1:1;
            
            if(sum == 0) res = max(res, i+1);
            
            /*Used find method to check if key existed in map*/
            if(m.find(sum) == m.end()) m[sum] = i;
            else res = max(res, i-m[sum]);
            
            // if (m[sum] == 0) m[sum] = i+1;
            // else res = max(res, i+1-m[sum]);
        }
        return res;
    }
};
