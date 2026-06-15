class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int minV = 0;
        
        vector<vector<int>>dist(row, vector<int>(col, 0));
        queue<vector<int>>q;
        int numberOfFresh = 0;
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                }else if(grid[r][c] == 1) {
                    dist[r][c] = INT_MAX;
                    numberOfFresh++;
                }
            }
        }
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
        while(!q.empty()){
             vector<int>top = q.front();
             q.pop();
             int r = top[0];
             int c = top[1];
             for(int i = 0; i < 4; i++){
                 int newr = r + dir[i][0];
                 int newc = c + dir[i][1];
                 if(newr>=0&&newc>=0&&newr<row&&newc<col&&grid[newr][newc]!=0){
                     if(grid[newr][newc] != 2) {
                         grid[newr][newc] = 2;
                         numberOfFresh--;
                     }
                     if(dist[r][c]+1 < dist[newr][newc]){
                         dist[newr][newc] = dist[r][c]+1;
                         q.push({newr, newc});
                         minV = max(minV, dist[newr][newc]);
                     }
                 }
             }
        }
        return numberOfFresh == 0 ? minV : -1;
    }
};
