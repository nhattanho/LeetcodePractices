class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto x:grid){
            int size = x.size();
            for(int i = 0; i < size; i++){
                if(x[i] < 0){
                    count+= size-i;
                    break;
                }
            }
        }
        return count;
    }
};
