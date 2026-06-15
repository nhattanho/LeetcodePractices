class Solution {
public:
    bool isvowel(char x){
        x = tolower(x);
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.length()-1;/*Space O(1)*/
        while(left < right){/*Time O(n)*/
            if(!isvowel(s[left])) left++;
            if(!isvowel(s[right])) right--;
            if(isvowel(s[left]) && isvowel(s[right])){
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
