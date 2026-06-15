class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return s;
        string res;
        int len = s.length()-1;

        // Handle post trailing space
        while(s[len] == ' '){
            len--;
        };

        string word = "";
        for(int i = len; i>= 0; i--){
            if(s[i] != ' '){
                word += s[i];
            } else {
                if(s[i] == ' ' && s[i+1] != ' '){
                    reverse(word.begin(), word.end());
                    word += ' ';
                    res += word;
                    word = "";
                }
            }
        }
        if(word == ""){
            res = res.substr(0, res.length()-1);
          // or: res.resize(res.length()-1);
        }else { // No pre-trailing space
            reverse(word.begin(), word.end());
            res += word;
        }

        return res;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return s;
        reverse(s.begin(), s.end());
        int left = 0;
        int len = s.length();

        // Removed pre-trailing space
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        // remove middle and pos-trailing space
        for(int move = i; move < len; move++){
            if(s[move] != ' ' || (move < len - 1 && s[move] == ' ' && s[move+1] != ' ')){
                s[left++] = s[move];
            }
        }
        s.resize(left);
        left = 0;
        int right = 0;
        for(i = 0; i < s.length(); i++){
            // swap each word
            if(s[i] == ' ' || i == s.length()-1){
                right = (i == s.length()-1) ? s.length()-1 : i-1;
                while(left <= right){
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++; right--;
                }
                left = i+1;
            }
        }
        return s;
    }
};
