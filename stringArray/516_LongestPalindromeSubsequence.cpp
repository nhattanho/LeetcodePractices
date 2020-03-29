/*Using DP with Time Complexity O(n^2) Space Complexity O(n^2)*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        if(len < 2) return len;
        vector<vector<int>>temp(len, vector<int>(len,0));
        for(int n = 1; n <= len; n++){
            for(int i = 0; i <= len-n; i++){
                int j = n+i-1;
                if(i == j) temp[i][j] = 1;
                else if(s[i] == s[j])
                    //when the string having the same value at start-i and end-j position,
                    //to find the longest Palindromic subsequence, we just need to find
                    //the longest substring between i and j. We don't care if temp[i][j]
                    // is equal n or not because we dont want to know the string "i.....j"
                    // is palindrome or not. We care about the longest subsequence.
                    temp[i][j] = temp[i+1][j-1] + 2;
                else
                    temp[i][j] = max(temp[i+1][j], temp[i][j-1]);
                //cout << "temp["<< i << "][" << j <<"]:" << temp[i][j] << endl;
            }
        }
	//Finally, the last element of first DP's row always saves the longest number 
        return temp[0][len-1];
    }
};
