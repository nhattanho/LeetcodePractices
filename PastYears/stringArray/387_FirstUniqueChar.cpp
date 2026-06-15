class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        vector<int>fre(26,0);
        for(auto x:s) fre[x-'a']++;
        for(int i = 0; i < len; i++)
            if(fre[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
