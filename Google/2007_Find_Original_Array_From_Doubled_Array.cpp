class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        int len = ch.size();
        if(len%2 != 0) return {};
        vector<int>ans;
        
        /*sort will help us check the original number first
        from the left => regconize the pair <original-changed>*/
        sort(ch.begin(), ch.end());
        
        unordered_map<int, int>m;
        for(auto x: ch)
            m[x] ++;
        
        for(int i = 0; i < len; i++){
            if(m[ch[i]] != 0 && m[ch[i]*2] != 0) {
                m[ch[i]]--;
                m[ch[i]*2]--;
                /*For special case that is [6,3,0,1]*/
                if(m[ch[i]] >= 0)
                    ans.push_back(ch[i]);
                if(ans.size() == len/2) return ans;
            }
        }
        return {};
        
        // for(int i = 0; i < len; i++){
        //     if(m[ch[i]] != 0){
        //         m[ch[i]]--;
        //         int temp = ch[i]*2;
        //         if(m[temp] != 0) {
        //             m[temp]--;
        //             ans.push_back(ch[i]);
        //             if(ans.size() == len/2) return ans;
        //         }else return {};
        //     }
        // }
        // return ans;
    }
};
