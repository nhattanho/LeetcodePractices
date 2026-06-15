class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp += nums[i];
            res.push_back(temp);
        }
        return res;
    }
};
