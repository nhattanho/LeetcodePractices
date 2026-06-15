class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& user, vector<int>& t, vector<string>& site) {
        unordered_map<string, map<int, string>>m; // ascending timestamp
        for(int i = 0; i < user.size(); i++){
            m[user[i]][t[i]] = site[i];
        }
        
        unordered_set<string>save;
        unordered_map<string, int>count;
        for(auto x: m){ // n/3 times <-> n/3 is the length of array user visiting 3-sequence pages in worst case
            auto pair = x.second;
            
            //check 3-sequence for each user
            for(auto it = pair.begin(); it != pair.end(); it++){ //n/3
                for(auto it1 = next(it); it1 != pair.end(); it1++){ // n/3
                    for(auto it2 = next(it1); it2!=pair.end(); it2++){ // n/3
                        string test = it->second + " " + it1->second + " " + it2->second;
                        save.insert(test); // using set to prevent the duplicated 3-sequence of the same user
                    }
                }
            }
            for(auto page: save) count[page]++;
            save.clear();
        }
        string res;
        int maxCount = 0;
        for(auto x: count){
            cout << x.first << " " << x.second << endl;
            if(x.second > maxCount){
                maxCount = x.second;
                res = x.first;
            }else if (x.second == maxCount){
                res = min(res, x.first);
            }
        }
        istringstream ss(res);
        string word;
        vector<string>result;
        while(ss >> word) {
            cout << word << " " << endl;
            result.push_back(word);
        }
        
        return result; // n^4
    }
};
