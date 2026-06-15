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

/*Optimal Solution
If the maximum sub-array is normal that means it will be on the original array
==> just apply Kadane's Algorithm. For example likes:
1 -2 3 -3 || 3 -1 2 -1 || 1 2 3 || -1 -2 -3 <=> [number max number] || [max number] || [number max]

However, the other case we need to focus on rotate array is the maximum sub-array
will be on both left and right of original array, like:
5 -2 1 -3 5 ==> in this time, the sum of middle has to be negative. And the maximum 
is 5 + 5 = 10. If the sum of middle is not negative, then the max sum has to be sum
of all numbers in the original array or we will come back to the first case. That's why
in the second case we can have the general format: [pos neg pos] ==> max + neg = sum

Since we know the first case always true with Kadane's Algorithm, so we need to separate
the second case. Also, in the second case, we can see if we get inverse, then the neg
becomes the maximum, and we can easily find it by using Kadane. Then the final max will be
sum + inverse(neg) ==> the maximum for the second case.

Nonetheless, when we get inverse, if the array is all negetive number, then apply the second case
will get the result = 0, but in the first case, the max has to be a negative number ==> if we compare
two result and get the max value ==> it will get the wrong result with max = 0. So, we need to care about
this case in the implementation.

Then we need to compare two case to get the result.
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, sum = 0, total_sum = 0;
        
        /*Apply Kadane in the first case*/
        for(int x:nums){
            total_sum += x;
            sum += x;
            sum = max(sum, x);
            max1 = max(sum, max1);
        }
        
        /*Check for the second case*/
        for(int &x:nums) x *= -1;
        sum = 0;
        for(int x:nums){
            sum += x;
            sum = max(sum, x);
            max2 = max(sum, max2);
        }
        max2 += total_sum;
        return max2 == 0 ? max1 : max(max1, max2);
    }
};

/*More readable code*/
class Solution {
public:
    int findMax(vector<int> nums){
        int sum = 0, res = INT_MIN;
        for(int x:nums){
            sum += x;
            sum = max(sum, x);
            res = max(sum, res);
        } 
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0, max1 = 0, max2 = 0;
        
        /*Apply Kadane in the first case*/
        max1 = findMax(nums);
        
        /*Check for the second case*/
        for(int &x:nums) {
            total_sum += x;
            x *= -1; 
        }
        max2 = findMax(nums);
        max2 += total_sum;
        return max2 == 0 ? max1 : max(max1, max2);
    }
};
