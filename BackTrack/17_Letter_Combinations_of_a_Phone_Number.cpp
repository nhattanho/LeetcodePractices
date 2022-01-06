/*Call N times <=> #digits recursion ==> space complexity O(N)
Besides, we can represent this problem likes a M-diary tree with
depth <=> N. For example: 
                                       ....
                                 a    b   c    d
                                /|\  /|\ /|\  /|\
                              ......................
Since the max #character is 4 ==> we could say this is 4-diary tree
==> the total path 4^N path. With each path, it runs N times for recursion
to form the word => time complexity is O(N*4^N)
*/

class Solution {
public:
    vector<string>mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};/*This vector is constant memory*/
    
    void getCombination(string word, vector<string>& res, int index, string digits){
        /*Base case*/
        if(word.length() == digits.length()) {
            res.push_back(word);
            return;
        }
        
        int num = digits[index] - '0';
        for(auto x:mapping[num-2]){
            word += x;
            getCombination(word, res, index+1, digits);
            word.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        int index = 0;
        string word = "";
        vector<string>res;
        getCombination(word, res, index, digits);
        
        return res;
    }
};

/*Using queue*/
/*
---
                              ""                                      <=> 3^0
            a                 b                  c                    <=> 3^1
         am an  ap        bm  bn   bp       cm  cn  cp                <=> 3^2
---
if we represent this problem into the tree, in the worst case that has 4 characters for
the digits like ""pqrs" => the space complexity is the diameter of the tree <=> maximum
length of queue <=> 4^N or generally, M^N with M is max #characters, N is #digits input

Besides, we go every node in the tree to form each string => time complexity = number of nodes
in tree ~ 1+M^1+M^2+....+M^N ~ M^N

Example for digits = "23"
q = {""}        q.empty() = false
q = {"a", "b", "c"}
q = {"b", "c", "ad", "ae", "af"}
q = { "c", "ad", "ae", "af", "bd", "be", "bf"}
q = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}
q = { "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"} ans = {"ad"}
q = { "af", "bd", "be", "bf", "cd", "ce", "cf"} ans = {"ad", "ae"}
q = { "bd", "be", "bf", "cd", "ce", "cf"} ans = {"ad", "ae", "af"}
q = { "be", "bf", "cd", "ce", "cf"} ans = {"ad", "ae", "af", "bd"}
q = {"bf", "cd", "ce", "cf"} ans = {"ad", "ae", "af", "bd", "be"}
q = {"cd", "ce", "cf"} ans = {"ad", "ae", "af", "bd", "be", "bf"}
q = {"ce", "cf"} ans = {"ad", "ae", "af", "bd", "be", "bf", "cd"}
q = {"cf"} ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce"}
q = {} ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}       q.empty = true
*/
class Solution {
public:
    vector<string>mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string>res;
        
        queue<string>q;
        q.push("");
        while(!q.empty()){
            string top = q.front();
            q.pop();
            
            /*Check for distinguishing each level in the tree*/
            int index = top.length();
          
            /*Completely form the word*/
            if(index == digits.length()) {
                res.push_back(top);
                continue;
            }
            
            int key = digits[index] - '0' - 2;
            for(auto x: mapping[key]){
                string word = top + x;
                q.push(word);
            }
        }
        
        return res;
    }
};

/*Iteration without using queue*/
class Solution {
public:
    vector<string>mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        
        vector<string>res(1,""); /*Space complexity <=> queue used in the previous approach*/
        vector<string>temp;
        /*Time complexity <=> previous approach*/
        for(auto x:digits){
            int index = x-'0'-2;
            for(auto& word:res){
                for(auto ch:mapping[index]){
                    temp.push_back(word+ch);
                }
            }
            res = move(temp); /*dont need to use clear if use move at here*/
            /*temp.clear();*/
        }
        
        return res;
    }
};
