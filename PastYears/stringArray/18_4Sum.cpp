// Time Complexity 0(k*n^3)
// Space 0(n^2) including the output
class Solution {
public:
    // Since isExisted is called inside the two-pointer loop, and the two-pointer loop may run O(n) times per (i, j) pair, 
    // the total time for isExisted checks per (i, j) pair is O(k*n), with k is the size of 2d nums.
    // The find algorithm iterates over up to k vectors, performing a constant-time comparison O(1) for each.
    bool isExisted(vector<vector<int>> nums, vector<int> target){
        bool res = find(nums.begin(), nums.end(), target) != nums.end();
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < len - 3; i++){
            for(int j = i+1; j < len - 2; j++){
                vector<int> v;
                int left = j + 1;
                int right = len - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right]; // ==> can lead to overflow
                    if(sum == target){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        if(!isExisted(res, v))
                            res.push_back(v);
                        left++;
                        right--;
                        v.clear();
                    }
                    else if(sum > target){
                        right--;
                    }
                    else left++;
                }
            }
        }
        return res;
    }
};

// ==> better solution
// This optimized version achieves $ O(n^3) $ time complexity by avoiding the costly isExisted checks and handling duplicates inline.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < len - 3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                vector<int> v;
                int left = j + 1;
                int right = len - 1;
                while(left < right){
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        res.push_back(v);
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                        v.clear();
                    }
                    else if(sum > target){
                        right--;
                    }
                    else left++;
                }
            }
        }
        return res;
    }
};
