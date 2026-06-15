class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int remain = target - nums[i];
            if(m.count(remain) != 0){
                return {m[remain], i};
            }else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
