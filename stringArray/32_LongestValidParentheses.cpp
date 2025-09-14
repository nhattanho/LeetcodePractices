class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>pos;
        int len = s.length();
        stack<int> st; st.push(-1);
        int maxlen = 0;

        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) st.push(i); // add a new base value which is index
                else{
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }  
        return maxlen;
    }
};
