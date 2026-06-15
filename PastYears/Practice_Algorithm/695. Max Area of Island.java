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

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        boolean[][] seen = new boolean[grid.length][grid[0].length];
        int[][] coordinate = new int[][]{ {1,0},{-1,0},{0,1},{0,-1} };

        int ans = 0;
        for (int r0 = 0; r0 < grid.length; r0++) {
            for (int c0 = 0; c0 < grid[0].length; c0++) {
                if (grid[r0][c0] == 1 && !seen[r0][c0]) {
                    int shape = 0;
                    Stack<int[]> stack = new Stack();
                    stack.push(new int[]{r0, c0});
                    shape++;
                    seen[r0][c0] = true;
                    while (!stack.empty()) {
                        int[] node = stack.pop();
                        int r = node[0], c = node[1];
                        for (int k = 0; k < 4; k++) {
                            int nr = r + coordinate[k][0];
                            int nc = c + coordinate[k][1];
                            if (0 <= nr && nr < grid.length &&
                                    0 <= nc && nc < grid[0].length &&
                                    grid[nr][nc] == 1 && !seen[nr][nc]) {
                                stack.push(new int[] {nr, nc});
                                seen[nr][nc] = true;
                                shape++;
                            }
                        }
                    }
                    ans = Math.max(ans, shape);
                }
            }
        }
        return ans;
    }
}
