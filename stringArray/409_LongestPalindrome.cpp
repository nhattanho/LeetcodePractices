/*Easy Solution to deal with this problem*/
class Solution {
public:
    int longestPalindrome(string s){
        int len = s.length();
        vector<int>fre(127,0);
        int count = 0;
        for(auto x:s) fre[x]++;
        for(int i = 0; i < fre.size(); i++){
            if(fre[i]%2 != 0) count++;
        }
        return (count==0)?len:len-count+1;
    }
};

/*Funny solution by using xor method*/
class Solution{
public:
    int longestPalindrome(string s) {
        int len = s.length();
        if(s.length() == 0) return 0;
        string ans="";
        int count = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < len-1; i++){
            if( (s[i] ^ s[i+1]) == 0 ) count++;
            else if(count%2 == 0) ans += s[i], count = 0;
            else count = 0;
        }
        if(count%2 == 0) ans += s[len-1];
        if(ans.length() == len) return 1;
        else if(ans.length() == 0) return len;
        else return len-ans.length()+1;
    }
}
