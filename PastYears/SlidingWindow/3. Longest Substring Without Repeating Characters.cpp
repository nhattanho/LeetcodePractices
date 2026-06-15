/*
calculate the length
move left pointer in next position until the frequency of duplicated char = 0
*/
      
/*a a a a a a a a a a a a a a a a*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char, int>m; /*char, fre*/
        int left = 0;/*hegining position of new substring without repeating character*/
        int maxLen = 0;
        
        for(int i = 0; i < s.length(); i++){
            /*regconize duplicated*/
            if(m[s[i]]) {
                /*count length so far*/
                maxLen = max(maxLen, i-left);
                while(m[s[i]] != 0){
                    m[s[left++]] = 0;
                }
                m[s[left]] = 1;/*marked the first character of new substring as visited*/
                m[s[i]] = 1;/*since the duplicated has been removed in while loop, so also marked it as visited for the new one*/
            } else m[s[i]] = 1;
        }
        maxLen = max(maxLen, len-left);/*special case: abcdef <=> original string has no duplicated characters*/
        return maxLen;
    }
};

/*More optimal*/
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
                /*means the duplicated character happens in current checking substring, Oth.wise, not consider a duplicated
                since left is the start position for the new substring has no duplicated character, example
                    l       |At here, m[a] = 0 < l=2 ==> cdbea has no duplicated characters
                a b c d b e a g
                */
                if(left <= m[s[i]]){
                    maxLen = max(maxLen, i-left);
                    left = m[s[i]]+1;/*move to next position for left pointer*/
                    m[s[i]] = i;/*update new position for the duplicated character*/
                }else m[s[i]] = i; /*update new position for character exist again but not duplicated for the current substring*/
            }else m[s[i]] = i;/*save the position for character*/
        }
        maxLen = max(maxLen, len-left);
        return maxLen;
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
                /*means the duplicated character happens in current checking substring, Oth.wise, not consider a duplicated
                since left is the start position for the new substring has no duplicated character, example
                    l       |At here, m[a] = 0 < l=2 ==> cdbea has no duplicated characters
                a b c d b e a g
                */
                if(left <= m[s[i]]){
                    maxLen = max(maxLen, i-left);
                    left = m[s[i]]+1;/*move to next position for left pointer*/
                }
                m[s[i]] = i;/*Reduce the duplicated line in the above code*/
            }else m[s[i]] = i;/*save the position for character*/
        }
        maxLen = max(maxLen, len-left);
        return maxLen;
    }
};
