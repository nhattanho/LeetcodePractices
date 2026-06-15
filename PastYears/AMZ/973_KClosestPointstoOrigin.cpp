class Solution {
public:
         vector<vector<int>> kClosest(vector<vector<int>> &p, int k) {
         multimap<int,int> m;
         
         //NlogN
         for(int i=0; i<p.size();i++){
              int dis = p[i][0]*p[i][0]+p[i][1]*p[i][1]; 
              m.insert({dis,i}); //logN
          }
          
         vector<vector<int>>v;
         for(auto it=m.begin();k>0;it++,k--) 
         v.push_back(p[it->second]);
         return v;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int K) {
        int len = p.size(); 
        priority_queue<pair<int, int>>q;
        
        // NlogK
        for(int i = 0; i < len; i++){
            int dis = p[i][0]*p[i][0] + p[i][1]*p[i][1];
            if(q.size() < K){
                q.push({dis, i});    
            }else{ // delete the largest distance to keep K elements
                if(dis < q.top().first){
                    q.pop();
                    q.push({dis,i});
                }
            }
        }
        vector<vector<int>>res;
        while(!q.empty()){
            auto x = q.top();
            q.pop();
            res.push_back(p[x.second]);
        }
        return res;      
    }
};


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
            auto x = q.top();
            q.pop();
            res.push_back(p[x.second]);
        }
        return res;      
    }
};
