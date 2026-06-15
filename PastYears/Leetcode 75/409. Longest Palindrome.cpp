class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>m;
        int count = 0;
        for(auto i:s){
            m[i]++;
            if(m[i]%2 == 0) count++;
        }
        return (count*2 == s.length()) ? s.length() : 2*count+1;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>m(126,0);
        int count = 0;
        for(auto i:s){
            m[i]++;
            if(m[i]!= 0 && m[i]%2 == 0) count++;
        }
        return (count*2 == s.length()) ? s.length() : 2*count+1;
    }
};
