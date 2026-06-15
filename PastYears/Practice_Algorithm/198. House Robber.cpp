class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if(size < 3) return size == 1? nums[0]: max(nums[0], nums[1]);
        
        nums[1] = max(nums[1], nums[0]);
        for(int i = 2; i < size; i++){
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        return nums[size-1];
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        int tmp = 0;
        for(int i = 2; i < len; i++){
            if(i == 2) nums[i] += nums[i-2];
            else nums[i] = max(nums[i] + nums[i-2], nums[i]+nums[i-3]);
        }
        return max(nums[len-1], nums[len-2]);
    }
};
