/*Time: 0(mn), space 0(1)*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto found = 0;
        for(auto i: s){
            found = t.find_first_of(i, found);
            if(found == std::string::npos) return false;
            else found++;
        }
        
        return true;
    }
};

/*Time 0(m+n), space 0(n)*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        unordered_map<int, char>m;
        for(int i = 0; i < s.length(); i++) m[i] = s[i];
            
        int count = 0;
        
        for(int i = 0; i < t.length(); i++){
            if(t[i] == m[count]){
                count++;
                if(count == s.length()) return true;
            }    
        }
        
        return false;
    }
};
