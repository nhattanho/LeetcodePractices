class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        multimap<long, vector<int>>m;/* space O(k)*/
        for(auto x:p){ /*n ==> Time complexity O(nlogk)*/
            long sum = x[0]*x[0]+x[1]*x[1];
            if(m.size() < k)
                m.insert({sum, x}); /*O(logk)*/
            else{
                if(prev(m.end())->first > sum){
                    m.erase(prev(m.end()));
                    m.insert({sum, x});
                }
            }
        }
        vector<vector<int>>res;
        for(auto it = m.begin(); it != m.end(); it++) res.push_back(it->second);
        // int i = 0;
        // for(auto it = m.begin(); it != m.end() & i < k; it++, i++){
        //     res.push_back(it->second);
        // }
        return res;
    }
};

/*Use queue*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int K) {
        int len = p.size(); 
        priority_queue<pair<int, int>>q;
        
        for(int i = 0; i < len; i++){
            int dis = p[i][0]*p[i][0] + p[i][1]*p[i][1];
            
            if(q.size() >= K && dis < q.top().first) q.pop();
            if(q.size() < K) q.push({dis, i});
        }
        vector<vector<int>>res;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            res.push_back(p[x.second]);
        }
        return res;      
    }
};
