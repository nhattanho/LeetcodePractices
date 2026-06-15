class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        
        for(auto x: s){
            if(st.empty() || x != st.top().first){
                st.push({x,1});
            } else{
                st.top().second++;
                if(st.top().second == k) st.pop();
            }
        }
        string res = "", temp = "";
        while(!st.empty()){
            temp = "";
            auto top = st.top();
            temp.append(top.second, top.first);
            res = temp + res;
            st.pop();
        }
        return res;
    }
};
