class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == 0){
                if(i != len-count){
                    nums.push_back(0);
                    nums.erase(nums.begin()+i);
                    i--;
                    count++;
                }else break;
            }
        }   
    }
};

/*Easier Solution to understand*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        if(l != 0){
            int count = 0;
            for(int i = 0; i < l; i++)
                if(nums[i]!= 0) nums[count++] = nums[i];
            for(int i = count;i<l; i++) nums[i]=0;
        }
    }
};
