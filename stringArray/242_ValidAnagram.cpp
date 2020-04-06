/*Using sort function in C++ with Time complexity O(nlogn), Space O(1)*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(), t.end());
        return s.compare(t)==0?true:false;
    }
};

/*Using hash technique to reduce Time complexity to O(n), Space O(n)*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>fre(26,0);
        for(auto x:s) fre[x-'a']++;
        for(auto x:t) fre[x-'a']--;
        for(auto x:fre)
            if(x != 0) return false;
        return true;
    }
};
