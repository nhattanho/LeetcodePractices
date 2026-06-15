class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lens = s.length();
        int lenp = p.length();
        if (lens == 0 || lenp == 0) return res;
        map<char, int> map;
        int l = 0, count = 0;
        for (auto x: p) map[x]++; // map[a] = 1, map[b] = 1, map[c] = 1
        
        for (int i = 0; i < lens; i++){
            if(map[s[i]] != 0) {
                count++;
                map[s[i]]--;
                if (count - l == lenp){
                    res.push_back(l);          
                }
                
            } else {
                map[s[l]]++;
                l++;
                i--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lens = s.length();
        int lenp = p.length();
        if (lens == 0 || lenp == 0) return res;
        map<char, int> map;
        int l = 0;
        for (auto x: p) map[x]++; // map[a] = 1, map[b] = 1, map[c] = 1
        
        for (int i = 0; i < lens; i++){
            if(map[s[i]] != 0) {
                map[s[i]]--;
                if (i - l + 1 == lenp){
                    res.push_back(l);          
                }
                
            //frequency of character = 0 <=> could not exist an anagram substring =>
            //reset the map and move the left pointer to the new checked substring 
            } else { 
                map[s[l]]++;
                l++;
                i--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        if(lenp > lens) return {};
        vector<int>v;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i = 0; i < lenp; i++){
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
        }
        if(v1 == v2) v.push_back(0);
        for(int i = 1; i <= lens-lenp; i++){
            v1[s[i-1]-'a']--;
            v1[s[i+lenp-1]-'a']++;
            if(v1 == v2) v.push_back(i);
        }
        return v;
    }
};
