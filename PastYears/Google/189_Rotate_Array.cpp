class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        
        for(int i = 0; i < len - k; i++){
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + len-k);
    }
};

/*More optimal with space complexity O(1)*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        
    }
};
