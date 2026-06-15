class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m; /*value,index => space O(n)*/
        for(int i = 0; i < nums.size(); i++){ /*Time O(n)*/
            int comp = target - nums[i];
            if(m.count(comp)) return {m[comp], i+1};
            m[nums[i]] = i+1;
        }
        return {};
    }
};

/*Another approach by using two pointers since array has been sorted already*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int sum = nums[l]+nums[r];
            if(sum == target) return {l+1, r+1};
            if(sum > target) r--;
            else l++;
        }
        return {0,0};
    }
};
