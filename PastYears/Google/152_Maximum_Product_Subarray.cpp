/*Refer: https://leetcode.com/problems/maximum-product-subarray/discuss/1328132/Simple-and-easy-C%2B%2B-code-with-explanation*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = nums[0];
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        for(int i = 1; i < size; i++){
            int temp_max = max(max(max_so_far*nums[i], nums[i]), min_so_far*nums[i]);
            min_so_far = min(min(max_so_far*nums[i], nums[i]), min_so_far*nums[i]);
            max_so_far = temp_max;
            res = max(res, max_so_far);
        }
        return res;
    }
};
