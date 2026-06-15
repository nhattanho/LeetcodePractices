/* Funny solution, Time complexity O(n^2), Space O(1)*/
class Solution {
public:
    bool checkAnagram(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1.compare(s2) == 0)return true;
        return false;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans(strs.size());
        int count = 0;
        while(strs.size() != 0){
            string temp = strs[0];
            for(int j = 0; j < strs.size(); j++){
                if(checkAnagram(temp, strs[j])){
                    ans[count].push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                    j--;
                }
            }
            count++;
        }
        ans.resize(count);
        return ans;
    }
};

/* Time complexity O(n), Space O(n)*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>save;
        for(auto x:strs){
            string temp = x;
            sort(temp.begin(), temp.end());
            save[temp].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto x:save){
            ans.push_back(x.second);
        }
        return ans;
    }
};
