/*Using erase feature of string, Time Complexity O(n^2), Space O(1)*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                if(i == 0){
                    s.erase(i,1);//O(n)
                    i-=1;
                }else{
                    s.erase(i-1,2);
                    i-=2;
                }
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                if(i == 0){
                    t.erase(i,1);
                    i-=1;
                }else{
                    t.erase(i-1,2);
                    i-=2;
                }
            }
        }
        return (s==t)?true:false;
    }
};

/*Time complexity O(n), SpaceO(n)*/
class Solution {
public:
    string reduceBackspace(string s){
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '#') ans+=s[i];
            else if(s[i] == '#' && ans.length()!=0)
                ans.pop_back();
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        return (reduceBackspace(s)==reduceBackspace(t))?true:false;
    }
};

//Better performance with Time Complexity O(n), Space O(1)
class Solution {
public: 
    string get(string s){
        int lens = s.length(), pos = 0;
        for(int i = 0; i < lens; i++){
            if(s[i] == '#'){
                pos--;
                if(pos<0) pos = 0;
                /*if(pos>=0) s[pos] = NULL;*/
            }
            else s[pos++] = s[i];
        }
        return s.substr(0, pos);
    }
    
    bool backspaceCompare(string s, string t) {
        return (get(s) == get(t))?true:false;
    }
};
