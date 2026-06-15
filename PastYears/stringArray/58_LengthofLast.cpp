/*version 1*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        int count = 0, flag = 0, end = 0;
        for(int i = l-1; i >= 0; i--){
            if(s[i] != ' '){
                if(flag == 0) flag =1, end = i;
                if( i == 0) return end+1;
            } 
            else if(s[i] == ' ' && flag == 1) return end-i;
        }
        return end;
    }
};

/*version 2*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream iss(s);
        string s1 ="";
        for(string s; iss >>s;) s1 = s;
        return s1.length();
    }
}
