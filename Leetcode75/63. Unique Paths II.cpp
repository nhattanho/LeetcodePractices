class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(r == 0 && c == 0){
                    grid[r][c] = 1;
                    continue;
                }
                if(grid[r][c] == 0){
                    if(r-1 >= 0 && grid[r-1][c] != -1 && c-1>=0 && grid[r][c-1]!=-1)
                        grid[r][c] = grid[r-1][c] + grid[r][c-1];
                    else if( (r-1<0 || grid[r-1][c] == -1) && c-1>=0 && grid[r][c-1]!=-1)
                        grid[r][c] = grid[r][c-1];
                    else if( (c-1<0 || grid[r][c-1] == -1) && r-1>=0 && grid[r-1][c] != -1)
                        grid[r][c] = grid[r-1][c];
                    else grid[r][c] = 0;
                }else grid[r][c] = -1;
            }
        }
        return grid[row-1][col-1];
    }
}

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return 0;
        grid[0][0] = 1;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 0){
                  if(r-1>= 0 && grid[r-1][c] != -1) grid[r][c] += grid[r-1][c];
                  if(c-1>=0 && grid[r][c-1] != -1) grid[r][c] += grid[r][c-1];
                }else if(!(r== 0 && c==0)) grid[r][c] = -1;
            }
        }
        return grid[row-1][col-1];
    }
}

class Solution {
    public int count = 0;

    public void helper(int[][]grid, int r, int c){
        if(c>=grid[0].length || r>=grid.length || grid[r][c]==1) return;
        if(r == grid.length-1 && c == grid[0].length-1) count++;

        helper(grid, r, c+1);
        helper(grid, r+1, c);
    }

    public int uniquePathsWithObstacles(int[][] grid) {
        if(grid[0][0] == 1 || grid[grid.length-1][grid[0].length-1] == 1) return 0;
        helper(grid, 0, 0);
        return count;
    }
}
