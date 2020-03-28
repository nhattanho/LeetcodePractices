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
