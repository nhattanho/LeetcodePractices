/*Stupid sliding window with time complexity O(n^2)*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, count = 0;
        while(true){
            while(nums[left] != 0){
                left++;
                if(left == nums.size()) return;
            }
            count = 0;
            for(int i = left+1; i < nums.size(); i++){
                if(nums[i] != 0){
                    swap(nums[left], nums[i]);
                    left++;
                    break;
                } else{
                    count++;
                    if(count == nums.size()-1-left) return;
                }
            }
            if(nums[left] == 0 && left == nums.size()-1) return;
        }   
    }
};

/*Optimal solution*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) nums[left++] = nums[i];
        }
        for(int i = left; i <  nums.size(); i++){
            nums[i] = 0;
        }
    }
};

/*Other optimal solution*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) swap(nums[i], nums[left++]);
        }
    }
};
