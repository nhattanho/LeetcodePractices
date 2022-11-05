/*
Firstly, we can easy to think about the 2 pointers to check both side of
the string to know if there is a sub palindrome. Then, since it is too
complicated to run all of cases of 2 pointers ==> we think about the
DP 2 pointers<=> 2D
So, we will see:
+ If s[left] = s[right], then
    dp[left][right] = dp[i][j] = max(dp[i][j-1], dp[i+1][j])
+ If s[left] = s[right], then
    if substring from left+1->right-1 is also palindrome (I)
        dp[i][j] = dp[i+1][j-1] + 2;
    else dp[i][j] = 1

As we can see, we are using dp[i][j] to save the max length of current 
palindrome from i->j ==> dp[i+1][j-1] is also palindrom <=> j-i-1 = dp[i+1][j-1]
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int checkLen = 1, start = 0;
        vector<vector<int>>dp(len, vector<int>(len,0));
        for(int dis = 0; dis < len; dis++){
            for(int i = 0; i < len-dis; i++){
                int j = i+dis;
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] != s[j]){
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }else{
                    dp[i][j] = (dp[i+1][j-1]==j-i-1)?(dp[i+1][j-1]+2):1;
                    if(dp[i][j] > checkLen) {
                        checkLen = dp[i][j];
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, checkLen);
    }
};
