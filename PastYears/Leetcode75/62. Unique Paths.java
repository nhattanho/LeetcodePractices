class Solution {
    public int uniquePaths(int m, int n) {
        int[][]dp = new int[m][n];
        Arrays.stream(dp).forEach(a -> Arrays.fill(a, 1));
        for(int r = m-2; r>= 0; r--){
            for(int c = n-2; c>= 0; c--){
                dp[r][c] = dp[r+1][c]+dp[r][c+1];
            }
        }
        return dp[0][0];
    }
}

class Solution {
    public int uniquePaths(int m, int n) {
        int[][]dp = new int[m][n];
        Arrays.stream(dp).forEach(a->Arrays.fill(a,1));
        for(int r = 1; r <= m-1; r++){
            for(int c = 1; c <= n-1; c++){
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
    }
}
