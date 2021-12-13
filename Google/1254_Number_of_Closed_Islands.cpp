/* IMPORTANT NOTE: Refer: https://leetcode.com/problems/number-of-closed-islands/discuss/546884/C%2B%2B-easy-DFS-(faster-than-99.81-memory-less-than-100)
    WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
    BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
    HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
*/
class Solution {
public:
    
    bool getIsland(vector<vector<int>>& g, int r, int c){
        if(r < 0 || r >= g.size() || c < 0 || c>= g[0].size()) return false;
        if(g[r][c] == 1) return true;
        
        g[r][c] = 1;
        bool a1 = getIsland(g, r-1, c);
        bool a2 = getIsland(g, r, c+1);
        bool a3 = getIsland(g, r, c-1);
        bool a4 = getIsland(g, r+1,c);
        return a1&&a2&&a3&&a4;
    }
    
    int closedIsland(vector<vector<int>>& g) {
        int row = g.size();
        int col = g[0].size();
        int res = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(g[r][c] == 0){
                    if(getIsland(g, r, c))
                        res++;
                }
            }
        }
        return res;
    }
};
