class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<int>minRows;
        vector<int>maxCols;
        for(auto x:matrix){
            minRows.emplace_back(*min_element(x.begin(), x.end()));
        }
        for(int i = 0; i < matrix[0].size(); i++){
            for(int j = 1; j < matrix.size(); j++){
                if(matrix[0][i] < matrix[j][i])
                    matrix[0][i] = matrix[j][i];
            }
            maxCols.emplace_back(matrix[0][i]);
        }
        for(auto x:minRows){
            for(auto y:maxCols){
                if(x==y) ans.emplace_back(x);
            }
        }
        return ans;
    }
};
