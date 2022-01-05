/*Brute force*/

class Solution {
public:
    
    bool checkPermutation(int len1, int start, string s2, string s1){
        string substring = s2.substr(start, len1);/*n1 times*/
        sort(substring.begin(), substring.end());/*n1logn1 times*/
        sort(s1.begin(), s1.end());
        return s1==substring;
    }
    
    /* Time complexity n2*n1*log(n1) */
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        for(int i = 0; i < s2.length(); i++){/*n2 time*/
            bool res = checkPermutation(len1, i, s2, s1) ;
            if(res) return true;
        }
        return false;
    }
};

/*More optimal*/
class Solution {
public:
    
    bool compareString(string s1, string s2){
        vector<int>ch(26,0);/*space constant*/
        for(int i = 0; i < s1.length(); i++){
            int index1 = s1[i]-'a';
            int index2 = s2[i]-'a';
            ch[index1]++;
            ch[index2]--;
        }
        for(auto x:ch){
            if(x!=0) return false;
        }
        return true;
    }
    
    bool checkPermutation(int len1, int start, string s2, string s1){
        string substring = s2.substr(start, len1);/*n1 times*/
        if(substring.length() != s1.length()) return false;
        return compareString(substring, s1);/*n1 times*/
    }
    
    /* Time complexity n2*n1*/
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        for(int i = 0; i < s2.length(); i++){/*n2 time*/
            bool res = checkPermutation(len1, i, s2, s1) ;
            if(res) return true;
        }
        return false;
    }
};

/*Sliding approach*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        
        unordered_map<char, int>m;
        for(auto x:s1) m[x]++;
        int left = 0;
        for(int i = 0; i <= len2-len1; i++){/*n2 time*/
            if(m[s2[i]] != 0){
                left = i;
                while(i < len2 && m[s2[i]] != 0){
                    m[s2[i]]--;
                    i++;
                }
                if(i-left != len1){
                    if(i == len2) return false;
                    int left_temp = left;
                    while(left < i){
                        m[s2[left]]++;
                        left++;
                    }
                    i = left_temp;
                }else return true;
            }
        }
        return false;
    }
};
/*Slide with more optimal*/
class Solution {
public:
    
    bool checkString(int start, int len, string s2, unordered_map<char, int> m){
        for(int i = start; i < start+len; i++){
            m[s2[i]]--;
            if(m[s2[i]] < 0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        
        unordered_map<char, int>m;/*Space constant since there are only 26 characters*/
        for(auto x:s1) m[x]++;
        /*Time complexity n1*(n2-n1)*/
        for(int i = 0; i <= len2-len1; i++){/*n2-n1 time*/
            if(m[s2[i]] != 0){
                bool check = checkString(i, len1, s2, m);/*n1 times*/
                if(check) return true;
            }
        }
        return false;
    }
};

/*Slide with more optimal*/
class Solution {
public:
    
    bool checkMap(unordered_map<char, int>m1, unordered_map<char, int>m2){
        for(char x = 'a'; x <= 'z'; x++){
            if(m1[x] != m2[x]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        
        unordered_map<char, int>m1, m2;/*constant space with max 26 characters, btw, can use vector for better space though still have O(1) for space complexity*/
        for(auto x:s1) m1[x]++;
        int left = 0;
      /*Time complexity O(n2)*/
        for(int i = 0; i < len2; i++){/*n2 time*/
            if(i<len1) m2[s2[i]]++; /*Can reduce the increasing*/
            if(i >= len1){
                m2[s2[i]]++;
                m2[s2[left++]]--;/*sliding window left here*/
            }
            if(checkMap(m1,m2)) return true; /*constant time with 26 time for each checking*/
        }
        return false;
    }
};
