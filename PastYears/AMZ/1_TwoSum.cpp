class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int>fre; // space: O(n)
        vector<int> res;
        
        // count frequency of each number & save the position ==> O(n)
        for(int i = 0; i < len; i++){
            int remainder = target - nums[i];
            if(fre.count(remainder) == 0) { // check if key is existed in map
                fre[nums[i]] = i;  
            }
            else {
                res.push_back(i);
                res.push_back(fre[remainder]);
            }
        }
        return res;
        
    }
};
