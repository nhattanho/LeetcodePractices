/*This code does not work since with 0, we dont process it as a 0 distance,
so run top-left and right-bottom will not solve the minimum steps correctly
For example: 
[[2,0,1,1,1,1,1,1,1,1],
 [1,0,1,0,0,0,0,0,0,1], ==> will make a wrong calculating the distance
 [1,0,1,0,1,1,1,1,0,1],
 [1,1,1,1,1,1,1,1,1,1]]
*/
class Solution {
    public int orangesRotting(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[][]dist = new int[row][col];
        Arrays.stream(dist).forEach(a->Arrays.fill(a, 0));
        int numberOfFresh = 0;
        for(int r = 0; r<row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1){
                    dist[r][c] = Integer.MAX_VALUE;
                    // numberOfFresh++;
                }
            }
        }
        int minV = 0;        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1){
                    int tmp = Integer.MAX_VALUE;
                    if(r-1>=0&&grid[r-1][c]!=0) tmp = Math.min(tmp, dist[r-1][c]);
                    if(c-1>=0&&grid[r][c-1]!=0) tmp = Math.min(tmp, dist[r][c-1]);
                    if(tmp == Integer.MAX_VALUE)
                        dist[r][c] = Math.min(dist[r][c], tmp);
                    else 
                        dist[r][c] = Math.min(dist[r][c], tmp+1);
                }
            }
        }
        
        for(int r = row-1; r>=0; r--){
            for(int c = col-1; c>=0; c--){
                if(grid[r][c] == 1){
                    int tmp = Integer.MAX_VALUE;
                    if(r+1<row&&grid[r+1][c]!=0) tmp = Math.min(tmp, dist[r+1][c]);
                    if(c+1<col&&grid[r][c+1]!=0) tmp = Math.min(tmp, dist[r][c+1]);
                    if(tmp == Integer.MAX_VALUE)
                        dist[r][c] = Math.min(dist[r][c], tmp);
                    else 
                        dist[r][c] = Math.min(dist[r][c], tmp+1);
                    if(dist[r][c] != Integer.MAX_VALUE)
                        minV = Math.max(minV, dist[r][c]);
                    else numberOfFresh++;
                }
            }
        }
        
        
        return numberOfFresh == 0?minV:-1; 
    }
}
