/*
Time complexity 0(n^2)
Space 0(1)
Since this is a circle array so we will find the maximum sum of each array
in the cirle.
For example: 
1 -2 3 -2 => max1
-2 3 -2 1 => max2
3 -2 1 -2 => max3
-2 1 -2 3 => max4
==> res = max(max1->max4)
*/

class Solution {
public:
    
    int findMax(vector<int>nums, int start){
        int sum = 0, res = INT_MIN;
        for(int i = start; i < nums.size(); i++){
            sum += nums[i];
            if(sum < nums[i]) sum = nums[i];
            res = max(res, sum);
        }
        
        for(int i = 0; i < start; i++){
            sum += nums[i];
            if(sum < nums[i]) sum = nums[i];
            res = max(res, sum);
        }
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int size = nums.size();
        
        int res = INT_MIN, sum = 0;
        
        for(int i = 0; i < size; i++){
            sum = findMax(nums, i);
            res = max(res, sum);
        }
        return res;
    }
};

/*Optimal Solution*/
