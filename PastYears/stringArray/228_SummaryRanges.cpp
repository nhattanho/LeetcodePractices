/* Time Complexity O(n), Space O(1)*/
class Solution {
public:
    void push(int start, int end, vector<string>&ans){
        string temp = "";
        if(start == end) temp = to_string(start);
        else
            temp += to_string(start) + "->" + to_string(end);
        ans.push_back(temp);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> ans;
        if(len == 0) return ans;
        int start = nums[0];
        for(int i = 0; i < len; i++){
            if(i == len-1) push(start, nums[i], ans);
            else if(nums[i] + 1 != nums[i+1]){
                push(start, nums[i], ans);
                start = nums[i+1];
            }
        }
        return ans;
    }
};
