/*DFS ==> find all paths => time complexity 2^(m*n)*/
class Solution {
public:
    void findP(int& count, int r, int c, int row, int col){
        if(r >= row || c >= col) return;
        if(r == row-1 && c == col-1 ) {
            count++;
            return;
        }
            
        findP(count, r, c+1, row, col);
        findP(count, r+1, c, row, col);
    }
    
    int uniquePaths(int m, int n) {
        int count = 0;
        findP(count, 0, 0, m, n);
        return count;
    }
};

class Solution {
public:
    //dp[r][c] = dp[r][c+1] + dp[r+1][c]
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1] = 1;
        
        for(int r = m-1; r>= 0; r--){
            for(int c = n-1; c >= 0; c--){
                if(r == m-1) dp[r][c] = 1;
                if(c == n-1) dp[r][c] = 1;
                
                if(r+1 < m && c+1 < n)
                    dp[r][c] = dp[r][c+1] + dp[r+1][c];
            }
        }
        return dp[0][0];
    }
};
