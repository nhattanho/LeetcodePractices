class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> res;
        //save the position && value ==> using the map ==> check if the key exist
        unordered_map<int, int> fre; // key, value = position
        for(int i = 0; i < len; i++){
            int remain = target - numbers[i];
            if(fre.count(remain) == 0) fre.insert({numbers[i], i});
            else {
                res.push_back(fre[remain]+1);
                res.push_back(i+1);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        int l = 0, r = len-1;
        while(l < r){
            if(nums[l] + nums[r] < target){
                l++;
            } else if(nums[l] + nums[r] > target) r--;
            else {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
        }
        return res;
    }
};
