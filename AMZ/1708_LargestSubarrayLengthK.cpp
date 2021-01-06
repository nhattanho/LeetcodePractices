class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        
        int pos = 0;
        for(int i = 0; i < len-k+1; i++){
            if(nums[i] > nums[pos]) {
                pos = i;
            }
        }
        vector<int>res;
        for(int i = pos; i < pos+k; i++){
            res.push_back(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        auto pos = max_element(nums.begin(), nums.end()-k+1);
        return vector<int>(pos, pos+k);
                               
    }
};
