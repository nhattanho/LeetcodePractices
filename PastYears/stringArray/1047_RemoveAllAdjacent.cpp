/* Time Complexity O(n), Space O(n)*/
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(ans.length() != 0 && s[i] == ans.back()) ans.pop_back();
            else ans+=s[i];
        }
        return ans;
    }
};

/* Time Complexity O(n), Space O(1)*/
class Solution {
public:
    string removeDuplicates(string s) {
        int pos = 0;
        for(int i = 1; i < s.length(); i++){
            if( pos < 0 || s[pos] != s[i] )
                s[++pos] = s[i];  
            else pos--;
        }
        return s.substr(0, pos+1);
    }
};
