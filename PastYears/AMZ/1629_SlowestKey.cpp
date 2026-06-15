class Solution {
public:
    char slowestKey(vector<int>& re, string key) {
        //find the time for each character ==> using the map: character, time ==> return the max time
        int len = re.size(); // l >= 2
        
        map<char, int> res;
        res.insert({key[0], re[0]});
        
        char ret = key[0];
        int checktime = re[0];      
        
        for(int i = 1; i < len; i++){
            int time = re[i] - re[i-1];
            if(time >= res[key[i]]) res[key[i]] = time;
            
            if((res[key[i]] == checktime && key[i] > ret)  || res[key[i]] > checktime ){
                checktime = res[key[i]];
                ret = key[i];
            }
        }
        
        return ret;
    }
};
