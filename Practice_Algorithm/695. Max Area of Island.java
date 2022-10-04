class Solution {
    public int findArea(int[][]grid, int r, int c, int count){
        if(r < 0 ||  r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0)
            return count;
        count++;
        grid[r][c] = 0;
        count = findArea(grid, r+1, c, count);
        count = findArea(grid, r-1, c, count);
        count = findArea(grid, r, c+1, count);
        count = findArea(grid, r, c-1, count);
        return count;
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int res = 0;
        for(int r = 0; r < row; r++ ){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1) {
                    int count = 0;
                    res = Math.max(res, findArea(grid, r, c, count));
                }
            }
        }
        return res;
    }
}
