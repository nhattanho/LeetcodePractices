/*
We need to count exactly number of subarray that has product is less than K.
Firstly, we need to calculate the product, than whenever the product < K, we
count the subarray. So, the way to count the value is so important. For example
we have an array: 
[0] [1] [2] [3] [4]
[10, 5,  2,  1,  6] K = 100

At index = 0, 10 < 100 ==> have only 1 subarray
index = 1 => 10*5 = 50 < 100 => we have 2 sub that are 5 and (10,5)
Since, each number is positive, then if nums[1]*nums[2]*nums[3] < K
then nums[3], (nums[2], nums[3]), and (nums[3],nums[2],nums[1]) has to
be less than K. Based on this analysis, we can see, at each index whose
product < K, we will count the number of subarray at this index from the
right to left. 

If product >= K, we devide it for the far left of the product until product < K
and continue applying the counting.

Therefore, go through all elements of the array, we will count correctly
total number of satisfied subarray.
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, product = 1, count = 0;
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i];
            while(product >= k){
                product /= nums[left];
                left++;
                if(left > i) break; /*This check for case all element > K, [5,6,7,8] and K = 1*/
            }
            if(i >= left)
                count += i-left+1;
        }
        return count;
    }
};
