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
