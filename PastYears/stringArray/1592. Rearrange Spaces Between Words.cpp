class Solution {
public:
    
    void countSpace_Word(string test, int& count_space, int& count_word) {
        bool check_word = false;
        for(auto x:test){ 
            if(x == ' ') {
                count_space++;
                check_word = false;
            }
            else {
                if(!check_word) {
                    check_word = true;
                    count_word++;
                }
            }
        }
    }
    
    string reorderSpaces(string text) {
        int count_space = 0, count_word = 0, max_space = 0, last_space = 0;
        countSpace_Word(text, count_space, count_word);
        
        if(count_word == 1) last_space = count_space;
        else{
            max_space = count_space/(count_word-1);
            last_space = count_space%(count_word-1);    
        }   
            
        istringstream ss(text);
        string s, res = "";
        int count = 0;
        while(ss >> s){
            count++;
            if(count == count_word)
                s.append(last_space, ' ');
            else 
                s.append(max_space, ' ');
            res += s;
        }
        return res;
    }
};

/*More readable*/
:class Solution {
public:
    
    int count_Word(string test) {
        bool check_word = true;
        int count_word = 0;
        for(auto x:test){ 
            if(isalpha(x) && check_word){
                check_word = false;
                count_word++;
            } else if(!isalpha(x)) check_word = true;
        }
        return count_word;
    }
    
  /*Time complexity O(n), Space O(1) if we dont care about the output return*/
    string reorderSpaces(string text) {
        int count_space = count(text.begin(), text.end(), ' ');
        int count_word = count_Word(text);
        
        int last_space = count_word==1?count_space:(count_space%(count_word-1));
        int max_space = count_word==1?0:count_space/(count_word-1);
          
        istringstream ss(text);
        string s, res = "";
        int count = 0;
        while(ss >> s){
            count++;
            if(count == count_word)
                s.append(last_space, ' ');
            else 
                s.append(max_space, ' ');
            res += s;
        }
        return res;
    }
};
