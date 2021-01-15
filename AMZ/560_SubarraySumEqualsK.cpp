class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int>m; // Space O(n)
        int sum = 0, count = 0;
        for(int i = 0; i < len; i++){ // Time O(n)
            sum += nums[i];
            if(sum == k) count++; //sub array from the i = 0 ==> to the current position
            
            int remain = sum-k;
            if(m[remain] != 0) // smaller sub array from i -> current position
                count += m[remain]; //for edge case: [0 0 0 0 0 0 0 0 0 0] k = 0
            m[sum]++;
        }
        return count;
    }
};
