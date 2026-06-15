class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 1) return s;
        
        //create the DP table
        // dp[i][j] is to save the longest length of substring from i to j
        vector<vector<int>> dp(len, vector<int>(len,0));
        int dis = 0, longest = 1, start = 0;
        string res;
        
        while(dis < len){
            for(int i = 0;  i < len; i++){
                int j = i + dis;
                if(j >= len) break;
                if(i == j) dp[i][j] = 1;
                else{
                    if(s[i] != s[j]){
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                        if(longest < dp[i][j] ){
                            longest = dp[i][j];
                            start = i;
                            
                            /*We dont need to compare as 2 lines below, because if actually the longest < dp[i][j] ==> we have already calculated the
                            value of dp[i][j-1] and dp[i+1][j]*/
                            // if(dp[i][j-1] > dp[i+1][j]) start = i;
                            // else start = i+1;
                        }
                        
                    }else{
                        /* we can use:
                        dp[i][j] = (dp[i+1][j-1] == j-i+1-2) ? (dp[i+1][j-1] + 2) : 1; OR
                        dp[i][j] = (dp[i+1][j-1] == j-i+1-2) ? (dp[i+1][j-1] + 2) : max(dp[i][j-1], dp[i+1][j]);
                        ==> it means the second parameter does not matter, because we just focus on new longest substring
                        if it not, we don't need to calculate because we have already the longest before that.
                        */
                        dp[i][j] = (dp[i+1][j-1] == j-i+1-2) ? (dp[i+1][j-1] + 2) : dp[i+1][j-1];
                        if(longest < dp[i][j]){
                            longest = dp[i][j];
                            start = i;
                        }
                        
                    }
                }
            }
            dis++;
        }
        return s.substr(start, longest);
    }
};


/*Reduce*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 1) return s;
        //create the DP table
        vector<vector<int>> dp(len, vector<int>(len,0));
        int dis = 0, longest = 1, start = 0;
        string res;
        while(dis < len){
            for(int i = 0;  i < len; i++){
                int j = i + dis;
                if(j >= len) break;
                if(i == j) dp[i][j] = 1;
                else{
                    if(s[i] != s[j]) dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                    else{
                        dp[i][j] = (dp[i+1][j-1] == j-i+1-2) ? (dp[i+1][j-1] + 2) : 1;
                        if(longest < dp[i][j]){
                            longest = dp[i][j];
                            start = i;
                        }
                        
                    }
                }
            }
            dis++;
        }
        return s.substr(start, longest);
    }
};



class Solution {
public:
    int checkPalindrome(string s, int left, int right){
        while(left >=0 && right <s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        int len1 = 0, len2 = 0, max_len = 0;
        int start = 0, end = 0;
        
        for(int i = 0; i < len; i++){
            len1 = checkPalindrome(s,i,i);
            len2 = checkPalindrome(s,i,i+1);
            max_len = max(len1, len2);
            if(max_len > end-start+1){
                start = i - (max_len-1)/2;
                end = i + max_len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
