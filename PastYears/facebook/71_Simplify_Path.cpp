/*Time complexity O(N), and space O(N)*/

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string ans = "";
        string s = "";
        stack<string>st;
        stringstream ss(path);
        while(getline(ss, s, '/')){
            if(s == "." || s == "") continue;
            if(s == ".." && !st.empty()) st.pop();
            if(s!="..") st.push(s);
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans==""?"/":ans;
    }
};
