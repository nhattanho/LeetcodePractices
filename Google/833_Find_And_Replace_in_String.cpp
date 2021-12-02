class Solution {
public:
    unordered_map<int, string>m_source, m_target;
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int len = indices.size();
        for(int i = 0; i < len; i++){
            m_source[indices[i]] = sources[i];
            m_target[indices[i]] = targets[i];
        }
        
        sort(indices.begin(), indices.end());
        string res = "";
        int start = 0, end = 0;
        
        for(int i = 0; i < len; i++){
            end = indices[i];
            if(start > end) return s; //check for overlap
            int l = m_source[indices[i]].length();
            
            if(s.substr(indices[i], l) == m_source[indices[i]]){
                for(int j = start; j < end; j++)
                    res += s[j];
                                 
                res += m_target[indices[i]];
                start = indices[i] + l;
            }
        }
        for(int i = start; i < s.length(); i++){
            res += s[i];
        }
        /*Or res += s.substr(start, s.length()-start);*/
        return res;
    }
};

/*More optimal*/
class Solution {
public:
    vector<pair<int,int>>ind_pos;
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int len = indices.size();
        for(int i = 0; i < len; i++){
            //save position for each indice
            ind_pos.push_back({indices[i], i});
        }
        
        /*klogk - k is the length of indices*/
        sort(ind_pos.begin(), ind_pos.end());
        
        string res = "";
        int start = 0, end = 0;
        
        /*O(n) - n is the length of original string*/
        for(int i = 0; i < len; i++){
            end = ind_pos[i].first;
            int pos = ind_pos[i].second;
            if(start > end) return s;
            int l = sources[pos].length();
            
            if(s.substr(end, l) == sources[pos]){
                res += s.substr(start, end-start);                  
                res += targets[pos];
                start = end + l;
            }
        }
        res += s.substr(start, s.length()-start);
        return res;
    }
};

/*Optimal by going from right to left*/
