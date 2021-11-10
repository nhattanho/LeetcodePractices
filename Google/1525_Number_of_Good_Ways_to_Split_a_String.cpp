Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.

class Solution {
public:
    int numSplits(string s) {
        int len = s.length();
        vector<int>diff1(len,0), diff2(len,0);
        unordered_map<char, int>fre;
        int count = 0;
        for(int i = 0; i < len; i++) {
            fre[s[i]]++;
            diff1[i] = fre.size();  
        }
        fre.clear();
        for(int i = s.length()-1; i >= 0; i--) {
            fre[s[i]]++;
            diff2[i] = fre.size();        
        }
        
        for(int i = 0; i< s.length()-1; i++){
            if(diff1[i] == diff2[i+1]) count++;
        }
        return count;
    }
};

/*
The other way can keep track the right side but still go from the left side is 
+ Go from the left side and keep track every frequency character of right side by subtracting 
+ Count how many distinct character of the right side after substracting
*/
class Solution {
public:
    int numSplits(string s) {
        int len = s.length();
        unordered_map<char, int>fre1, fre2;
        int count = 0;
        for(int i = 0; i < len; i++) fre1[s[i]]++;
        for(int i = 0; i < len; i++) {
            /*Use the left side to count for the right side*/
            fre1[s[i]]--;
            if(fre1[s[i]] == 0) fre1.erase(s[i]);
            
            /*This is count for the left side*/
            fre2[s[i]]++;
            
            /*Compare the number of distinct characters*/
            if(fre1.size() == fre2.size()) count++;
        }
        return count;
    }
};
