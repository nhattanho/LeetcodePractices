class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>m;
        unordered_map<char, int> m2;
        for(int i = 0; i < s.length(); i++){
            if(m.count(s[i])){/*0(1)*/
                if(m[s[i]] != t[i]) return false;
            }else {
                m[s[i]] = t[i];
                m2[t[i]]++;
                if(m2[t[i]] > 1) return false;
            }
        }
        return true;
    }
};
