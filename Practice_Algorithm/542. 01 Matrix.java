class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    for (int k = 0; k < rows; k++) {
                        for (int l = 0; l < cols; l++) {
                            if (matrix[k][l] == 0) {
                                int dist_01 = abs(k - i) + abs(l - j);
                                dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
                            }
                        }
                    }
                }
            }
        }
        return dist;
    }
};

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int row = mat.length;
        int col = mat[0].length;
        int[][] dist = new int[row][col];
        Queue<int[]>q = new LinkedList<>();
        
        Arrays.stream(dist).forEach(a->Arrays.fill(a,Integer.MAX_VALUE));
        for(int r = 0; r < row; r++){
            for(int c = 0; c< col; c++){
                if(mat[r][c] == 0){
                    dist[r][c] = 0;
                    q.add(new int[]{r,c});
                }
            }
        }
        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()!=0){
            int[] top = q.poll();
            int r = top[0];
            int c = top[1];
            for(int i = 0; i<4; i++){
                int newr = r + dir[i][0];
                int newc = c + dir[i][1];
                if(newr >= 0 && newc >= 0 && newr < row && newc < col && mat[newr][newc] == 1){
                    if(dist[r][c] + 1 < dist[newr][newc]){
                        dist[newr][newc] = dist[r][c] + 1;
                        q.add(new int[]{newr, newc});
                    }
                }
            }
        }
        return dist;
    }
}



class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int row = mat.length;
        int col = mat[0].length;
        int[][] dist = new int[row][col];
        Arrays.stream(dist).forEach(a->Arrays.fill(a,Integer.MAX_VALUE));
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c< col; c++){
                if(mat[r][c] == 0)  dist[r][c] = 0;   
            }
        }
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c< col; c++){
                if(mat[r][c] != 0){
                    int tmp = Integer.MAX_VALUE;
                    if(r-1>=0) tmp = Math.min(tmp, dist[r-1][c]);
                    if(c-1>=0) tmp = Math.min(tmp, dist[r][c-1]);
                    if(tmp != Integer.MAX_VALUE) dist[r][c] = tmp+1;
                }
            }
        }
        
        for(int r = row-1; r >= 0; r--){
            for(int c = col-1; c>=0; c--){
                if(mat[r][c] != 0){
                    int tmp = Integer.MAX_VALUE;
                    if(c+1<col) tmp = Math.min(tmp, dist[r][c+1]);
                    if(r+1<row) tmp = Math.min(tmp, dist[r+1][c]);
                    if(tmp != Integer.MAX_VALUE) dist[r][c] = Math.min(dist[r][c], tmp+1);
                }
            }
        }
        
        return dist;
    }
}
