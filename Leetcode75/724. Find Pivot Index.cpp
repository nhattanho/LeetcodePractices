class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        int left = 0, right = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) left = 0;
            else left += nums[i-1];
            right = sum - nums[i] - left;
            if(left == right) return i;
        }
        
        return -1;
    }
};


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum += x;
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum-nums[i];
            if(left == sum) return i;
            left += nums[i];
        }
        return -1;
    }
};


