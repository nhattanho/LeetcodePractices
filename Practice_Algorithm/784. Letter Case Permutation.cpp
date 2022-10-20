class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res = {""};
        vector<string>save;
        for(auto x:s){
            for(auto y:res){
                if(isalpha(x)){
                    save.push_back(y+string(1,tolower(x)));
                    save.push_back(y+string(1,toupper(x)));
                }else save.push_back(y+x);
            }
            res = move(save);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string>v;
        vector<string>v1;
        v.push("");
 
        for(auto x: s){
            while(v.size() != 0){
                int size = v.size();
                for(int i = 0; i < size; i++){
                    string word = v.front();
                    v.pop();
                    if(isalpha(x)){
                        word += toupper(x);
                        v.push(word);
                        word.pop_back();
                        word += tolower(x);
                        v.push(word);
                    }else{
                        word += x;
                        v.push(word);
                    }
                }
                break;
            }
        }
        while(!v.empty()){
            v1.push_back(v.front());
            v.pop();
        }
        return v1;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string>v;
        vector<string>v1;
        v.push("");
 
        for(auto x: s){
            
            int size = v.size();
            for(int i = 0; i < size; i++){
                string word = v.front();
                v.pop();
                if(isalpha(x)){
                    word += toupper(x);
                    v.push(word);
                    word.pop_back();
                    word += tolower(x);
                    v.push(word);
                }else{
                    word += x;
                    v.push(word);
                }
            }
 
        }
        while(!v.empty()){
            v1.push_back(v.front());
            v.pop();
        }
        return v1;
    }
};
