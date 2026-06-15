class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        reverse(nums.begin(),nums.begin()+len-k);
        reverse(nums.begin()+len-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        vector<int>tmp(len);
        for(int i = 0; i < len; i++){
            int temp = (i+len-k)%len;
            tmp[i] = nums[temp];
        }
        nums = tmp;
    }
};
