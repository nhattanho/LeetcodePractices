/*
whenever the current sum < 0:
+ Next number is negative ==> max will or not need to be updated
-2 -1 => updated max from -2 -> -1 
-2 -5 => no need to update current max = -2
==> reset sum = 0

+ Next number is positive ==> max should be equal this positive number

Whenever the current sum >= 0:
+ Next number is negative ==> check and update max, continue adding next number in case [14 -1 26]
+ Next number is positive ==> check, update max, continue adding

Or on the other hand, we could say:
max of sum(0,i) at a[i] = a[i] + (sum(0,i-1) < 0 ? 0 : sum(0,i-1))
==> will update a[i] as the maximum sum from the left until position ith.

if(sum < 0) {
    sum = nums[i];
    maxNum = max(maxNum, sum);
}else {
    sum += nums[i];
    nums[i] = max(nums[i], sum);
    maxNum = max(maxNum, nums[i]);
}
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0, smax = INT_MIN;
//         for (int num : nums) {
//             sum += num;
//             smax = max(smax, sum);
//             if (sum < 0) {
//                 sum = 0;
//             }
//         }
//         return smax;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int sum = 0, maxNum = INT_MIN;
        
//         for(int i = 0; i < len; i++){
//             sum += nums[i];
//             maxNum = max(sum, maxNum);
//             if(sum < 0) sum = 0;
//         }
//         return maxNum;
//     }
// };


// public int maxSubArray(int[] nums) {
// 	if (nums == null || nums.length == 0) { return 0; }
// 	int max = nums[0], sum = nums[0];
// 	for (int i = 1; i < nums.length; i++) {
// 		if (sum < 0) { sum = nums[i]; }
// 		else {sum += nums[i]; }
// 		max = Math.max(max, sum);
// 	}
// 	return max;
// }


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxNum = nums[0], sum = nums[0];
//         for(int i = 1; i < nums.size(); i++){
//             if(sum < 0) sum = 0;
//             sum += nums[i];
//             nums[i] = max(nums[i], sum);
//             maxNum = max(maxNum, nums[i]);
//         }
//         return maxNum;
//     }
// };
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = INT_MIN, sum = 0; 
//         for(int i = 0; i < nums.size(); i++){
//             sum += nums[i];
//             if(sum <nums[i]){
//                 sum = nums[i];
//             }
//             res = max(res, sum); 
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < nums[i]) sum = nums[i];
            res = max(res, sum);
        }
        return res;
    }
};
