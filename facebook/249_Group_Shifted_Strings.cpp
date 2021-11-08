class Solution {
public:
    
    string shift(string x){
        int dis = x[0] - 'a';
        int temp = 0;
        x[0] = 'a';
        for (int i = 1; i < x.length(); i++){
            temp = x[i] - 'a';
            if(temp < dis) temp = temp+26-dis;
            else temp = temp - dis;
            x[i] = 'a' + temp;
        }
        return x;
    }
    
    vector<vector<string>> groupStrings(vector<string>& str) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>>ans;
        for(auto x: str){
            m[shift(x)].push_back(x);
        }
        
        for(auto [word, v]: m){
            ans.push_back(v);
        }
        return ans;
    }
};
