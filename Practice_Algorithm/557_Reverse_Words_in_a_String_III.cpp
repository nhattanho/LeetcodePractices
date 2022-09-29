class Solution {
public:
    string doReverse(string s){
        reverse(s.begin(), s.end());
        return s+" ";
    }
    
    string reverseWords(string s) {
        string res = "", token = "";
        stringstream ss(s); /*Space O(L)*/
        while(getline(ss, token, ' ')){ /*m is the number of words*/
            res += doReverse(token);/*n is the max length of each words ==> Time O(mn) ~ O(L)*/
        }
        res = res.substr(0, res.length()-1);
        return res;
    }
};

/*Another approach*/
class Solution {
public:
    void doReverse(string& s,int start, int end){
        reverse(s.begin()+start, s.begin()+end);
    }
    
    string reverseWords(string s) {
        int start = 0, end = 0;/*Space O(1)*/
        for(int i = 0; i < s.length(); i++){ /*Time complexity O(L)*/
            if(s[i] == ' '){
                end = i;
                doReverse(s, start, end);/*max length of word could be assumed a constant*/
                start = i+1;
            }
        }
        end = s.length();
        doReverse(s, start, end);
        return s;
    }
};

/*Worked with List*/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        list<string>temp;
        
        stringstream character(s);
        string word;
        while(character >> word){
            temp.push_front(word); //Will take O(n) for pushing in front
        }
        string res;
        list<string>::iterator it;
        int count = 0;
        for(it = temp.begin(); it != temp.end(); it++){
            count++;
            res += *it;
            if(count !=temp.size())
                res += " ";
        }
            
        return res;
    }
};

/*Worked with List but more optimization*/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        list<string>temp;
        
        stringstream character(s);
        string word;
        while(character >> word){
            temp.push_back(word);//take 0(1)
        }
        string res;
        int count = 0;
        for(auto it = temp.rbegin(); it != temp.rend(); it++){
            count++;
            res += *it;
            if(count !=temp.size())
                res += " ";
        }
            
        return res;
    }
};
