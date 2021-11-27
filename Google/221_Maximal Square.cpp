/*Time complexity 0(mn) Space 0(mn)*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        int dp[rows][cols];
        
        int maxSq = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                m[r][c] = m[r][c] - '0';
                if(r == 0 || c == 0) dp[r][c] = m[r][c];
                else {
                    if(m[r][c] != 0)
                        dp[r][c] = min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1])) + 1;
                    else dp[r][c] = 0;
                }
                maxSq = max(maxSq, dp[r][c]);
            }
        }
        return maxSq*maxSq;
    }
};
