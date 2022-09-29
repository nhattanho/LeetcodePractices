class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int l = 0, res = 0;
        for(int i = 0; i<s.length(); i++){
            char t = s[i];
            if(!m.count(t)) m[t] = 1;
            else {
                res = max(res, i-l);
                while(m.count(t)){
                    m.erase(s[l++]);
                }
                m[t] = 1;
            }
        }
        res = max(res,int(s.length()-l));
        return res; 
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int len = s.length();
        int l = 0, res = 0;
        for(int i = 0; i<s.length(); i++){
            char t = s[i];
            if(m[t] == 0) m[t]=1;
            else{
                res = max(res, i-l);
                m[s[l++]] = 0;
                i--;
            }
        }
        return max(res, len-l);
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char, int>m; /*char, fre*/
        int left = 0;/*hegining position of new substring without repeating character*/
        int maxLen = 0;
        
        for(int i = 0; i < len; i++){
            /*regconize two same character have existed in map*/
            if(m.count(s[i])){
                /*means the duplicated character happens in current 
                checking substring, Oth.wise, not consider a duplicated
                since left is the start position for the new substring 
                has no duplicated character, example
                    l       |At here, m[a] = 0 < l=2 ==> cdbea has no duplicated characters
                a b c d b e a g
                */
                if(left <= m[s[i]]){
                    maxLen = max(maxLen, i-left);
                    left = m[s[i]]+1;/*move to next position for left pointer*/
                }
            }
            m[s[i]] = i;
        }
        maxLen = max(maxLen, len-left);
        return maxLen;
    }
};
