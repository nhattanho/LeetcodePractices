class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.length();
        if(length == 1) return "";
        /*Not good at all
        for(int i = 0; i < length; i++){
            if(palindrome[i]!='a'){
                if(length%2 != 0 && i == length/2) continue;
                palindrome[i]='a';
                break;
            }
            if(i == length - 1) palindrome[i]='b';
        }
        return palindrome;
        */
        //Optimize solution
        for(int i = 0; i < length/2; i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[length-1] = 'b';
        return palindrome;
    }
};
