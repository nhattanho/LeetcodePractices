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

// class Solution {
// public:
    
//     void getString(string s, vector<string>&res, int index, string word){
//         if(index == s.length()){
//             res.push_back(word);
//             return;
//         }
        
//         if(isalpha(s[index])){
//             string first = word + string(1, tolower(s[index]));
//             string second = word + string(1, toupper(s[index]));
//             getString(s, res, index+1, first);
//             getString(s, res, index+1, second);
//         }else {
//             word += s[index];
//             getString(s, res, index+1, word);
//         }
//     }
    
//     vector<string> letterCasePermutation(string s) {
//         vector<string>res;
//         string word = "";
//         getString(s, res, 0, word);
//         return res;
//     }
// };
// class Solution {
// public:
//     vector<string> letterCasePermutation(string s) {
//         vector<string>res;
//         queue<string>q;
//         int index = -1;
//         string top = "";
//         q.push(top);
        
//         while(!q.empty()){
//             index++;
//             int size = q.size();
//             for(int i = 0; i < size; i++){//ab aB Ab AB
//                 string top = q.front();
//                 q.pop();
                
//                 if(top.length() == s.length()) {
//                     res.push_back(top);
//                     continue;
//                 }
                
//                 if(isalpha(s[index])){
//                     q.push(top + string(1, tolower(s[index]))); //ab
//                     q.push(top + string(1, toupper(s[index]))); //aB
//                 }else{
//                     q.push(top + string(1, s[index]));//a1
//                 }
//             }
//         }
//         return res;
        
//     }
// };

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>v;
        v.push_back("");
        for(auto x: s){
            int size = v.size();
            for(int i = 0; i < size; i++){
                string word = v[i];
                
                if(isalpha(x)){
                    word += toupper(x);
                    v[i] = word;
                    word.pop_back();
                    word += tolower(x);
                    v.push_back(word);
                }else{
                    word += x;
                    v[i] = word;
                }
            }
        }
        return v;
    }
};
























