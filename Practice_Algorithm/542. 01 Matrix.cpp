class Solution {
public:
    int minNum(int n1, int n2, int n3, int n4){
        int m1 = min(n1, n2);
        int m2 = min(n3, n4);
        return min(m1, m2);
    }
    
    int findD(vector<vector<int>>temp, int r, int c, int count){
        if(r < 0 || c < 0 || r >= temp.size() || c >= temp[0].size()) return INT_MAX;
        if(temp[r][c] == 2) return INT_MAX;
        
        if(temp[r][c] == 0) return count;
        
        temp[r][c] = 2;
        int num1 = findD(temp, r+1, c, count+1);
        int num2 = findD(temp, r-1, c, count+1);
        int num3 = findD(temp, r, c+1, count+1);
        int num4 = findD(temp, r, c-1, count+1);
        return minNum(num1, num2, num3, num4);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>resMax = mat;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(mat[r][c] == 1){
                    int count = 0;
                    int dis = findD(mat, r, c, count);
                    resMax[r][c] = dis;
                }
            }
        }
        return resMax;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>dist(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>>q;
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                if(mat[r][c] == 0) {
                    dist[r][c] = 0;
                    q.push({r,c});
                }
            }
        } 
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int i = 0; i < 4; i++){
                int newr = r + dir[i][0];
                int newc = c + dir[i][1];
                //coordination in the queue is the nearest to the 0, so for the new position,
                //just need to check when it is greater than the current + 1
                if(newr >=0 && newc >=0 && newr < row && newc < col && mat[newr][newc] == 1){
                    if(dist[r][c] + 1 < dist[newr][newc]){
                        //dist[newr][newc] = min(dist[newr][newc], dist[r][c]+1);
                        dist[newr][newc] = dist[r][c]+1;
                        q.push({newr,newc});
                    }                   
                }
            }
        }
        return dist;
    }
};
