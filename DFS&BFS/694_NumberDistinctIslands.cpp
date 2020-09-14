/* Time complexity 0(m*n), space complexity O(m*n), the worst case happens when the array is filled 
by all 1s */

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        map<vector<int>, int>coor; // using map to reduce the duplication
        vector<int>path;
        int count = 0;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++){
                if(grid[r][c] != 0) {
                    findPath(grid, col, row, r, c, path);
                    coor[path]++;
                    path.clear();
                }
            }
        }
        
        return coor.size();
    }
    void findPath(vector<vector<int>>&grid, int col, int row, int r, int c, vector<int>&path){
        if(c<0 || r<0 || c >= col || r >= row || grid[r][c] == 0) {
            path.push_back(0);
            return;
        }  
        path.push_back(1);
        grid[r][c] = 0;
        findPath(grid,col, row, r, c+ 1, path);
        findPath(grid,col, row, r+1, c, path);
        findPath(grid,col, row, r-1, c, path);
        findPath(grid,col, row, r, c-1, path);
    }
};
