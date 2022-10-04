class Solution {
public:
    void findArea(vector<vector<int>>& grid, int r, int c, int& count){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return;
        count++;
        grid[r][c] = 0;
        findArea(grid, r+1, c, count);
        findArea(grid, r-1, c, count);
        findArea(grid, r, c+1, count);
        findArea(grid, r, c-1, count);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c <col; c++){
                if(grid[r][c] == 1){
                    int count = 0;
                    findArea(grid, r, c, count);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findArea(vector<vector<int>>& grid, int r, int c, int count){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return count;
        count++;
        grid[r][c] = 0;
        count = findArea(grid, r+1, c, count);
        count = findArea(grid, r-1, c, count);
        count = findArea(grid, r, c+1, count);
        count = findArea(grid, r, c-1, count);
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c <col; c++){
                if(grid[r][c] == 1){
                    int count = 0;
                    res = max(res, findArea(grid, r, c, count));
                }
            }
        }
        return res;
    }
};
