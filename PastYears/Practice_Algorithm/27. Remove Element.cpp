class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int l = len-1;
        for(int i = 0; i <= l; i++){
            if(nums[i] == val){
                //swap and re-check for current pos
                nums[i--] = nums[l];
                nums[l--] = val;
            }
        }
        return l+1;
    }
};
