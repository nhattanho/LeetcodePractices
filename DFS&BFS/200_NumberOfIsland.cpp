/* DFS solution, Time Complexity O(m*n), space complexity O(m*n) in case the 2-D array is filled with all 1's value */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;   
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++) {
                if (grid[r][c] == '0') continue;
                findIsland(grid, row, col, r, c);
                count++;
            }
        }
        return count;
    }
    
    void findIsland(vector<vector<char>>&grid, int row, int col, int r, int c){
        if(r < 0 || c < 0 || c == col || r == row || grid[r][c] == '0') return;
        grid[r][c] = '0';
        findIsland(grid, row, col, r-1, c);
        findIsland(grid, row, col, r, c-1);
        findIsland(grid, row, col, r, c+1);//r=0 c=0 ==> r=0 c=1 => r=0 c=2
        findIsland(grid, row, col, r+1, c); //r=1 c=1
    }
};

/* BFS Solution, time complexity O(m*n), and space O(min(m,n)), because 
space complexity now is the maximum of queue we are using to save the values */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;   
        queue<pair<int, int>>q;//row, col
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++) {
                
                if (grid[r][c] == '0') continue;
                grid[r][c] = '0';
                q.push({r,c});
                
                while(q.size()!=0){
                    int len = q.size();
                    for(int i = 0; i < len; i++) {
                        pair<int,int>temp = q.front();
                        q.pop();
                        
                        if(temp.first>0 && grid[temp.first-1][temp.second]== '1'){
                            q.push({temp.first-1, temp.second});
                            grid[temp.first-1][temp.second] = '0';                            
                        }
                        if(temp.first + 1 < row && grid[temp.first+1][temp.second]== '1'){
                            q.push({temp.first+1, temp.second});
                            grid[temp.first+1][temp.second] = '0';                            
                        }
                        if(temp.second>0 && grid[temp.first][temp.second-1]== '1'){
                            q.push({temp.first, temp.second-1});
                            grid[temp.first][temp.second-1] = '0';                            
                        }
                        if(temp.second+1<col && grid[temp.first][temp.second+1]== '1'){
                            q.push({temp.first, temp.second+1});
                            grid[temp.first][temp.second+1] = '0';                            
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};

/* Reducing the code for BFS */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;   
        queue<pair<int, int>>q;//row, col
        vector<vector<int>>coordinate{{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++) {
                
                if (grid[r][c] == '0') continue;
                grid[r][c] = '0';
                q.push({r,c});
                
                while(q.size()!=0){
                    int len = q.size();
                    for(int i = 0; i < len; i++) {
                        pair<int,int>temp = q.front();
                        q.pop();
                        
                        for(auto coor: coordinate){
                            int x = temp.first +coor[0];
                            int y = temp.second + coor[1];
                            if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == '1'){
                                grid[x][y] = '0';
                                q.push({x,y});
                            }
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};
