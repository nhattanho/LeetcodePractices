// For example, we have ) ( ) ( ( ) ) ) 
//                index 0 1 2 3 4 5 6 7
// and then if we reduce the well-formed parentheses, the string will look like ) )
//                                                                              0 7
// then zero will be the first base to calculate the len, which is 6 - 0 = 6, then 7 will be the 
// next base for the next well-formed ones.
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

// Optimize solution with no extra memory by using two scans to cover all well-formed parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int left = 0, right = 0;
        int maxlen = 0;

        // The first scanning from left to right will miss cases such as: ( ( ( ( ( ) ) ()
        // However, if we start doing similar scanning from right to left, these cases will be covered.
        for (int i = 0; i < len; i++){
            if(s[i] == '(') left++;
            else right++;

            if(left == right)
                maxlen = max(maxlen, 2*right);
            else if(right > left){ // meet the base close and start the new well-formed
                right = 0;
                left = 0;
            }
        }
        left = 0, right = 0;
        for(int i = len-1; i >= 0; i--){
            if(s[i] == ')') right++;
            else left ++;

            if(right == left) maxlen = max(maxlen, 2*left);
            else if(left > right){ // meet the base open and start the new well-formed
                left = 0;
                right = 0;
            }
        }
        return maxlen;
    }
};
