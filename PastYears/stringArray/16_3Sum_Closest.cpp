
// Complexity Analysis
// Time Complexity:
// Sorting = O(n log n)
// Outer loop = O(n)
// Inner two-pointer loop = O(n)
// Total = O(n²)

// Space Complexity:
// Sorting is in-place.
// Only a few variables → O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        int res = INT_MAX;
        int closest = INT_MAX;
      
        for(int i = 0; i < len-2; i++){
            int left = i + 1;
            int right = len - 1;
            while(left < right){
                long sum = nums[i] + nums[left] + nums[right];
                int gap = abs(sum - target);
                if(gap < closest) { // report the closest as well as its sum
                    closest = gap;
                    res = sum;
                }
                if(sum == target) return sum;
                if(sum < target){ // need to have a larger sum to reduce the gap
                    left++;
                }
                else { // need to have a smaller sum to reduce the gap
                    right--;
                }
            }
        }
        return res;
    }
};
