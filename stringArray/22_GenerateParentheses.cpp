class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0, close = 0;
        string temp = "";
        backtrack(open, close, n, res, temp);
        return res;
    }

    void backtrack(int open, int close, int limit, vector<string>& res, string temp){
        // base case
        if(temp.length() == 2*limit){
            res.push_back(temp);
            return;
        }
        if(open < limit){ // "(("
            temp += "("; // "((("
            backtrack(open+1, close, limit, res, temp);
            temp.pop_back();
        }

        if(close < open){
            temp += ")";
            backtrack(open, close+1, limit, res, temp);
        }
    }
};
