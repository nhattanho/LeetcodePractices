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

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_point = 0, t_point = 0;
        
        while(s_point != s.length()){
            if(t.length() == 0) return false;
            if(s[s_point] == t[t_point]) s_point++;
            t_point++;
            if(s_point == s.length()) return true;
            if(t_point == t.length()) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_point = 0, t_point = 0;
        
        while(s_point < s.length() && t_point < t.length()){
            if(s[s_point] == t[t_point]) s_point++;
            t_point++;
        }
        return s_point == s.length();
    }
};
