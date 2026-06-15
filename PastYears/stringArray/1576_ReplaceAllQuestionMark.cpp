/* Time Complexity O(n), space: O(1) */
class Solution {
public:
    string modifyString(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] == '?'){
                for(char x = 'a'; x < 'z'; x++){
                    if((i == 0 && i < len-1 && x != s[i+1]) || len == 1){ // ?a or ?
                        s[i] = x;
                        break;
                    } else if (i == len-1 && x != s[i-1] && i >= 1){ // abc?
                        s[i] = x;
                        break;
                    } else if (i >= 1 && s[i-1] != x && i < len-1 && s[i+1] != x){ // abc?acb
                        s[i] = x;
                        break;
                    }
                }
            }
            
        }
        return s;
    }
};

/* Optimize */
class Solution {
public:
    string modifyString(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] == '?'){
                for(char x = 'a'; x < 'z'; x++){
                    if( ((i >= 1 && s[i-1] != x) || i == 0) && ((i < len-1 && s[i+1] != x) || (i == len-1)) ){
                        s[i] = x;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
