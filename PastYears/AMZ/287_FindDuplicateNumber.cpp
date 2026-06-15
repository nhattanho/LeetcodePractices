class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                if( (nums[i] ^ nums[j]) == 0) return nums[i];
            }
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < len; i++){
            if(nums[i-1] == nums[i]) return nums[i];
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for(auto x: nums){
            nums[(abs(x))] *= -1;
            if(nums[abs(x)] > 0) return abs(x);
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = nums[0], fast = nums[0];
        low = nums[low];
        fast = nums[low];
        while(low != fast){
            low = nums[low];
            fast = nums[nums[fast]];
        }
        low = nums[0];
        while(low != fast){
            low = nums[low];
            fast = nums[fast];
        }
        return low;
    }
};
