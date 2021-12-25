class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, product = 1, count = 0;
        /*0(n^2)*/
        while(left < nums.size()){ 
            product = 1;
            for(int i = left; i < nums.size(); i++){
                product *= nums[i];
                if(product < k) count++;
                else {
                    break;
                } 
            }
            left++;
        }
        return count;
    }
};

/*Optimal solution*/
