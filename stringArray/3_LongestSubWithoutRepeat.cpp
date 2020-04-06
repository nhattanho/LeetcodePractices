/*Time Complexity O(n), Space O(n)*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        string ans = "";
        int count = 0, max1 = 0;
        for(int i = 0; i < len; i++){
            size_t pos = ans.find(s[i]);
            if(pos == string::npos){
                ans += s[i];
                count++;
                max1 = max(max1, count);//saving the maximum length
            }else{
                //Repetition happening
                ans.erase(0,pos+1);
                ans += s[i];
                count = ans.length();//re_count
            }
        }
        return max1;
    }
};

/*Using the other solution*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int count = 0, max1 = 0, left = 0;
        vector<int>character(128,0);
        for(int i = 0; i < len; i++){
            if(character[s[i]] == 0){
                character[s[i]]++;
                count++;
                max1 = max(count-left, max1);
            }
            else{
                //if(s[left] == s[i]) character[s[left]] = 0;
                /*Move left-pointer until it meets the repeated character, and
                simulataneously, we reset the remark for every character before the
                repeated character. For example: a b c e d h e a b c Firstly, left = 0,
                when we meet the second e, we want to reset the remark for a b c, because
                after that we still want to get a b c for the string like "d h e a b c"*/
                character[s[left++]] = 0;
                i--;
            }
        }
        return max1;
    }
};
