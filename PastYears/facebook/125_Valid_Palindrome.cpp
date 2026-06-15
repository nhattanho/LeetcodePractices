/*Time Complexity 0(n), space O(1)*/
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int l = 0, r = len-1;
        
        while (l < r) {
            while(l < r && !isalnum(s[l])) {
                l++;            
            }
            while(r > l && !isalnum(s[r])){
                r--;
            }
        
            if(tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
