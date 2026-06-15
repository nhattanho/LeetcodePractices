class Solution {
    int count = 0;
    int[][]dir = {{1,0},{-1,0},{0,1},{0,-1}};
    public void countIs(char[][]m, int r, int c){
        if(r < 0 || c < 0 || r >= m.length || c>=m[0].length||m[r][c]=='0') return;
        
        m[r][c] = '0';
        for(int i = 0; i < 4; i++){
            int newr = r + dir[i][0];
            int newc = c + dir[i][1];
            countIs(m, newr, newc);
        }
    }
    
    public int numIslands(char[][] grid) {
        for(int r = 0; r < grid.length; r++){
            for(int c = 0; c < grid[0].length; c++){
                if(grid[r][c] == '1') {
                    countIs(grid, r,c);
                    count++;
                }
            }
        }
        return count;
    }
}

class Solution {
    public int numIslands(char[][] grid) {
        Queue<int[]>q = new LinkedList<>();
        int[][]dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int count = 0;
        for(int r = 0; r < grid.length; r++){
            for(int c = 0; c < grid[0].length; c++){
                if(grid[r][c] == '1') {
                    q.add(new int[]{r, c});
                    grid[r][c] = '0';
                    while(q.size()!=0){
                        int[]coor = q.poll();
                        int r1 = coor[0];
                        int c1 = coor[1];
                        for(int i=0; i<4; i++){
                            int newr = r1 + dir[i][0];
                            int newc = c1 + dir[i][1];
                            if(newc>=0&&newr>=0&&newr<grid.length&&newc<grid[0].length&&grid[newr][newc]!='0')
                            {
                                grid[newr][newc] = '0';
                                q.add(new int[]{newr, newc});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
}
