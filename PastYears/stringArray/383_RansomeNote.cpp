class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> testM, testR;
        for(auto x:magazine) testM[x]++;
        for(auto x:ransomNote) testR[x]++;
        for(auto x:ransomNote){
            if(testR[x] > testM[x]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> testM, testR;
        for(auto x:magazine) testM[x]++;
        for(auto x:ransomNote){
            testR[x]++;
            if(testR[x] > testM[x]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>test(26,0);
        for(auto x:magazine) test[x-'a']++;
        for(auto x:ransomNote){
            test[x-'a']--;
            if(test[x-'a'] < 0) return false;
        }
        return true;
    }
};
