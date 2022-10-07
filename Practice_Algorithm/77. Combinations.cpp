class Solution {
public:
    void getV(vector<int>& v, int start, int k, int n, vector<vector<int>>&res){
        if(k == 0) {
            res.push_back(v);
            return;
        }
        for(int i = start; i <= n; i++){
            v.push_back(i);
            getV(v, i+1, k-1, n, res);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        for(int i = 1; i <= n-k+1; i++){
            vector<int>tmp;
            tmp.push_back(i);
            getV(tmp, i+1, k-1, n, res);
        }
        return res;
    }
};
