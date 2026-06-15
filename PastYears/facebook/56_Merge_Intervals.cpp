#include <vector>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        //sort(inter.begin(), inter.end(), [](vector<int>v1, vector<int>v2)-> bool { return v1[0] < v2[0];});
        sort(inter.begin(), inter.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int start = inter[0][0], end = inter[0][1];
        for (int i = 1; i < inter.size(); i++){
            if (inter[i][0] > end) {
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                temp.clear();
                start = inter[i][0];
                end = inter[i][1];
                continue;
            } else {
                start = min(start, inter[i][0]);
                end = max(end, inter[i][1]);
            }
            
        }
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();



/*Another optimal approach*/
#include <vector>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        vector<vector<int>>ans;
        vector<int>temp{inter[0][0], inter[0][1]};
        ans.push_back(temp);
        for(auto ele: inter){
            if(ele[0] > ans.back()[1]) ans.push_back(ele);
            else {
                ans.back()[0] = min(ans.back()[0], ele[0]);
                ans.back()[1] = max(ans.back()[1], ele[1]);
            }
        }
        return ans;
    }
};
