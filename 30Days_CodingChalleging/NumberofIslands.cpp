/* Using DFS 
 * Example: 0 1 0 1 1
 *          1 1 0 1 1
 *          1 0 0 0 1
 *          1 1 1 1 1
 *
 * 0    1    0    1 <- 1
 *      |         |    ^
 *      v         |    |
 * 1 <- 1    0    1 <- 1
 * |                   ^ 
 * v                   |
 * 1    0    0    0    1
 * |                   ^
 * v                   |
 * 1 -> 1 -> 1 -> 1 -> 1
 */

class Solution {
public:
    char findNeighbor(int i, int j, int row, int col, vector<vector<char>>&grid){
        //right
        if(j+1 == col || grid[i][j+1] == '0') grid[i][j] = '0';
        else grid[i][j] = findNeighbor(i, j+1, row, col, grid);
        //down
        if(i+1 == row || grid[i+1][j] == '0') grid[i][j] = '0';
        else grid[i][j] = findNeighbor(i+1, j, row, col, grid);
        //top
        if(i-1 < 0 || grid[i-1][j] == '0') grid[i][j] = '0';
        else grid[i][j] = findNeighbor(i-1, j, row, col, grid);
        //left
        if(j-1 < 0 || grid[i][j-1] == '0') grid[i][j] = '0';
        else grid[i][j] = findNeighbor(i, j-1, row, col, grid);
        return grid[i][j];
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){//start checking the island
                    grid[i][j] = findNeighbor(i, j, row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    char findNeighbor(int i, int j, int row, int col, vector<vector<char>>&grid){
        if(j == col || i == row || j < 0 || i < 0 || grid[i][j] == '0') return '0';
        grid[i][j] = findNeighbor(i, j+1, row, col, grid);
        grid[i][j] = findNeighbor(i+1, j, row, col, grid);
        grid[i][j] = findNeighbor(i-1, j, row, col, grid);
        grid[i][j] = findNeighbor(i, j-1, row, col, grid);
	/*
        if(j == col || i == row || j < 0 || i < 0 || grid[i][j] == '0') return '0';
        grid[i][j] = '0';
        check(start + 1, end, grid);
        check(start -1, end, grid);
        check(start, end + 1, grid);
        check(start, end - 1, grid);
	 *
	 */
        return grid[i][j];
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = findNeighbor(i, j, row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

/* Using BFS */
class Solution {
public:
    vector<vector<int>> coordinate{{1,0}, {-1,0}, {0,1}, {0,-1}}; //row, col
    queue<pair<int, int>>que;

    void findNeighbor(int row, int col, vector<vector<char>>&grid){
        while(que.size() != 0){
            int size = que.size();
            for(int c = 0; c < size; c++){
                pair<int, int>temp = que.front();
                que.pop();
                //Checking for neighbor, down-top-right-left
                for(auto x:coordinate){
                    int i = temp.first+x[0];
                    int j = temp.second+x[1];
                   if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == '1'){
                        grid[i][j] = '0';
                        que.push({i,j});//saving new valid coordinate for new level
                   }
               }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){//finding the starting of the island
                    grid[i][j] = '0';
                    que.push({i,j});
                    findNeighbor(row,col,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
