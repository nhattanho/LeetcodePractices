class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, count = 1; 
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                count++;
                res = max(res, count);
            }else{
                count = 1;
            }
        }
        return res;
    }
};
