/* Naive Solution with Time Complexity O(mxn), Space O(1)*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenp = p.length();//m
        int lens = s.length();//n
        if(lens < lenp) return {};
        vector<int>res;
        sort(p.begin(), p.end());
        string temp = "";
        for(int i = 0; i <= lens-lenp; i++){
           for(int j = i; j < i+lenp; j++)
               temp += s[j];
            sort(temp.begin(), temp.end());
            if(temp.compare(p) == 0) res.push_back(i);
            temp = "";
        }
        return res;
    }
};

/* Optimal Solution by using Sliding Window.
 * Time complexity O(n), Space O(1)*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenp = p.length();
        int lens = s.length();
        if(lens < lenp) return {};
        vector<int>res, fre(26,0);
        for(auto x:p) fre[x-'a']++;
        int count = 0, left = 0;
        for(int i = 0; i < lens; i++){
            if(fre[s[i]-'a'] != 0){
                fre[s[i]-'a']--;
                count++;
                if(count-left == lenp) res.push_back(left);
            }else{
                fre[s[left++]-'a']++;
                //left++;
                i--;
            }
        }
        return res;
    }
};
