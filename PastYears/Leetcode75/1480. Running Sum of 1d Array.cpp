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

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};
