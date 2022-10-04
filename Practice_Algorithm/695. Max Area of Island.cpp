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

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        stack<vector<int>>st;
        for(int r = 0; r < row; r++){
            for(int c = 0; c <col; c++){
                if(grid[r][c] == 1){
                    st.push({r,c});
                    grid[r][c] = 0;
                    int count = 0;
                    while(!st.empty()){
                        vector<int>t = st.top();
                        st.pop();
                        count++;
                        int r = t[0];
                        int c = t[1];
                        if(r-1>=0 && grid[r-1][c] != 0){
                            st.push({r-1, c});
                            grid[r-1][c] = 0;
                        }
                        if(r+1 < row && grid[r+1][c] != 0){
                            st.push({r+1, c});
                            grid[r+1][c] = 0;
                        }
                        if(c-1>=0 && grid[r][c-1] != 0){
                            st.push({r, c-1});
                            grid[r][c-1] = 0;
                        }
                        if(c+1 <col && grid[r][c+1]!=0){
                            st.push({r, c+1});
                            grid[r][c+1] = 0;
                        }
                    }
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>>v = { {1,0},{-1,0},{0,1},{0,-1} };
    //int v[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        stack<vector<int>>st;
        for(int r = 0; r < row; r++){
            for(int c = 0; c <col; c++){
                if(grid[r][c] == 1){
                    st.push({r,c});
                    grid[r][c] = 0;
                    int count = 0;
                    while(!st.empty()){
                        vector<int>t = st.top();
                        st.pop();
                        count++;
                        int r = t[0];
                        int c = t[1];
                        
                        for(auto x: v){
                            int newr = r+x[0];
                            int newc = c+x[1];
                            if(newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] != 0) {
                                st.push({newr, newc});
                                grid[newr][newc] = 0;
                            }
                        }
                    }
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};
