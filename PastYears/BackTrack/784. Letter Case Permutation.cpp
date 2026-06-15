/*DFS
Each time of jumping, it forms a string => time complexity n*2^n, space O(n)
                a1b2
                 |
                a[0]
              /     \
             a[0]   A[0]
              |      |
             1[1]   1[1]
             a1      A1
             b|      b|  
            /  \  
           a1b a1B ................
            2|  2| 
           a1b2 a1B2 ...............    
*/
class Solution {
public:
    
    void getString(string s, vector<string>&res, int index, string word){
        if(index == s.length()){
            res.push_back(word);
            return;
        }
        
        if(isalpha(s[index])){
            string first = word + string(1, tolower(s[index]));
            string second = word + string(1, toupper(s[index]));
            getString(s, res, index+1, first);
            getString(s, res, index+1, second);
        }else {
            word += s[index];
            getString(s, res, index+1, word);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string word = "";
        getString(s, res, 0, word);
        return res;
    }
};

/*BFS*/
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        queue<string>q;
        int index = -1;
        string top = "";
        q.push(top);
        
        while(!q.empty()){ /*Time complexity <=> time go through all node of tree <=> 2^(n+1), space <=> diameter of tree <=> 2^n <=> #leaf node in the last level*/
            index++;
            int size = q.size();
            for(int i = 0; i < size; i++){//ab aB Ab AB
                string top = q.front();
                q.pop();
                
                if(top.length() == s.length()) {
                    res.push_back(top);
                    continue;
                }
                
                if(isalpha(s[index])){
                    q.push(top + string(1, tolower(s[index]))); //ab
                    q.push(top + string(1, toupper(s[index]))); //aB
                }else{
                    q.push(top + string(1, s[index]));//a1
                }
            }
        }
        return res;
        
    }
};

/*Iteration without using queue but same complexity for time and space*/
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
