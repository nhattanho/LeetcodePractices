/*Expand Around Center
 * Time Complexity O(n^2) Space O(1)*/
class Solution {
public:
    void checkPalindrome(string s, int left, int right, int& count){
        while(left >= 0 && right<= s.length() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int len1 = 0, len2 = 0;
        int count = 0;
        for(int i = 0; i < len; i++){
            checkPalindrome(s,i,i,count);
            checkPalindrome(s,i,i+1,count);
        }
        return count;
    }
};

/*Using another appoarch by DP
 * Time Complexity O(n^2) Space Complexity O(n^2)*/
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), count = 0;
        vector<vector<int>>temp(len, vector<int>(len,0));
        for(int n = 1; n <= len; n++){
            for(int i = 0, j = n+i-1; i <= len-n; i++, j++){
                if(i == j) temp[i][j] = 1;//Updating for diagonal
                else if(s[i] == s[j]){
                    if(temp[i+1][j-1]== n-2){
                        temp[i][j] = n;
                        count++; //counting the palindrome substring
                    }else temp[i][j] = 1;
                }else temp[i][j] = max(temp[i+1][j], temp[i][j-1]); //updating DP table
            }
        }
        return count+len;
    }
};
