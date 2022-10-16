class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>m;
        unordered_map<char, int> m2;
        for(int i = 0; i < s.length(); i++){
            if(m.count(s[i])){
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

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>m1;
        unordered_map<char, int> m2;
        for(int i = 0; i < s.length(); i++){
            if(!m1.count(s[i]) && !m2.count(t[i])){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }else if(!m1.count(s[i]) && m2.count(t[i])) return false;
            else if(m1.count(s[i]) && m1[s[i]] != t[i]) return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>v1(256, -1);
        vector<int>v2(256, -1);
        for(int i = 0; i < s.length(); i++){
            if(v1[s[i]] == -1){
                if(v2[t[i]] == -1){
                    v1[s[i]] = t[i];
                    v2[t[i]] = s[i];
                }else return false;
            }else if(v1[s[i]] != t[i]) return false;
        }
        return true;
    }
};
