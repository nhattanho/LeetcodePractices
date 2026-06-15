class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>test;
        
        vector<vector<string>>res;
        for (auto x: strs){
            string temp = x;
            sort(temp.begin(), temp.end());
            test[temp].push_back(x);
        }
        for(auto [key, vector] : test){
            res.push_back(vector);
        }
        return res;
    }
};

/*Optimize Time Complexity*/
class Solution {
public:
    /*lamp ==> [0 <=> a] = 1*/
    string strSort(string x){
        int check[26] = {0};
        //memset(check, 0, sizeof(check));
        for (auto character: x){
            check[character - 'a']++;
        }
        string res = "";
        for(int i = 0; i < 26; i++){
            res += check[i] + 'a' + i;
        }
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>test;
        
        vector<vector<string>>res;
        for (auto x: strs){
            string temp = strSort(x);
            test[temp].push_back(x);
        }
        for(auto [key, vector] : test){
            res.push_back(vector);
        }
        return res;
    }
};
