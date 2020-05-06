/* Using DFS */
class Solution {
public:
    int findPath(vector<vector<int>>&grid, int row, int col, int i, int j){
        /*instead of using 2 for loop for checking bound of matrix
        if(i == row-1 && j == col-1){
            return grid[i][j];
        }
        if(i+1 == row) return grid[i][j] + findPath(grid, row, col, i, j+1);
        if(j+1 == col) return grid[i][j] + findPath(grid, row, col, i+1, j);
	*/
        if(i+1 == row){
            int sum = 0;
            for(int c = j; c < col; c++) sum += grid[i][c];//bound of matrix
            return sum;
        }
        if(j+1 == col){
            int sum=0;
            for(int c = i; c < row; c++) sum += grid[c][j];//bound of matrix
            return sum;
        }
        int sum1 = grid[i][j] + findPath(grid,row, col, i, j+1);
        int sum2 = grid[i][j] + findPath(grid, row, col, i+1, j);
        return min(sum1, sum2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int i = 0, j = 0;
        return findPath(grid, row, col, i, j);
    }
};

/* Using DP to reduce time complexity to O(mxn), space O(1) */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0){
                    grid[i][j] += grid[i][j-1];
                } else if (j == 0)
                    grid[i][j] += grid[i-1][j];
                else {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[row-1][col-1];
    }
};

