class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int meet = 0;
        int left = 0;
        int res = 0;
        for(int i = 0; i < len; i++){
            if(i == 0 || nums[i] == nums[i-1]){
                meet++;
            }else meet = 1;

            if(meet < 3){
                res++;
                nums[left++] = nums[i];
            }
        }
        return res;
    }
};
