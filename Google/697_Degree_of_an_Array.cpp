class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int de = 0, res = INT_MAX;
        unordered_map<int, int>fre;
        for(auto x:nums){
            fre[x]++;
            de = max(de, fre[x]);
        }
        
        unordered_map<int, vector<int>>len;
        for(int i = 0; i < nums.size(); i++){
            if(fre[nums[i]] == de){
                len[nums[i]].push_back(i);
            }
        }
        
        for(auto [key, value]:len){
            res = min(res, value[value.size()-1] - value[0] + 1);
        }
        return res;
    }
};

/*More readable code*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int de = 0, res = INT_MAX;
        
        unordered_map<int, vector<int>>len;
        for(int i = 0; i < nums.size(); i++){
            len[nums[i]].push_back(i);
            if(len[nums[i]].size() > de) de = len[nums[i]].size();
        }
        
        for(auto [key, value]:len){
            if(value.size() == de)
                res = min(res, value[value.size()-1] - value[0] + 1);
        }
        return res;
    }
};
