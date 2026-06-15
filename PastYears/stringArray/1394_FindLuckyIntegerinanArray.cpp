/*Time Complexity O(n) Space O(n)*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        //unordered_map<int, int>temp;
        map<int, int>temp; //number, frequence
        int ans = -1, pre_ans = 0;
        for(auto x:arr) temp[x]++;
        for(auto x:temp){
            if(x.first == x.second){
                pre_ans = ans;
                ans = x.first;
                ans = max(pre_ans, ans);
            }
        }
        return ans;
    }
};
