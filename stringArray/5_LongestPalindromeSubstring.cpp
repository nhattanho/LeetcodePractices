/*Naive-Brute Force Solution-Time Complexity 0(n^3)*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0) return "";
        if(len == 1) return s;
        int right = 0, flag = 0, temp = 0;
        string ans = "", pre_ans = "";
        for(int i = 0; i < len-1; i++){
            right = len;
            while(right>i){
                right--;
                temp = right;
                /*flag helps to check whether there is a palindrome or not*/
                flag = 0;
                for(int j = i; j <= right; j++){
                    if(j == temp) break;
                    if(j>temp){
                        flag = 1;
                        break;
                    }
                    if(s[j] == s[temp]){
                        temp--;
                        if(temp == j) break;
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    pre_ans = ans;
                    ans =  s.substr(i, right-i+1);
                    /*get the longest substring palindrome*/
                    ans = (ans.length() > pre_ans.length())?ans:pre_ans;
                }
            }
        }
        return ans;
    }
};

/*Better solution by using DP, Expand Around Center, or Manacher Algorithm*/
/*1-Expand Around Center-Time Complexity 0(n^2)*/
class Solution {
public:
    int checkPalindrome(string s, int left, int right){
        while(left >=0 && right <s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;//number characters between left and right
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return s;
        int len1 = 0, len2 = 0, pos = 0, pre_pos = 0;
        int max_len = 0, pre_max = 0;
        for(int i = 0; i < len; i++){
            //get length of palindrom substring in case its length is odd
            len1 = checkPalindrome(s,i,i);
            //in case its length is even
            len2 = checkPalindrome(s,i,i+1);
            pre_max = max_len;
            pre_pos = pos;
            pos = i;
            //get the length of longest palindrom and save its middle position 
            max_len = max(len1, len2);
            if(max_len < pre_max){
                max_len = pre_max;
                pos = pre_pos;
            }
        }
        //get the longest substring base on its start position and length
        int start = (max_len%2 == 0)?(pos-max_len/2 + 1):(pos-max_len/2);
        return s.substr(start, max_len);
    }
};
/*Note: Instead of updating the length and the middle position of longest
 *substring, we can update the start and end position of it after every
 comparison*/
string longestPalindrome(string s) {
    int len = s.length();
    int len1 = 0, len2 = 0, max_len = 0;
    int start = 0, end = 0;
    for(int i = 0; i < len; i++){
        len1 = checkPalindrome(s,i,i);
        len2 = checkPalindrome(s,i,i+1);
        max_len = max(len1, len2);
        if(max_len > end-start+1){
            start = i - (max_len-1)/2;
            end = i + max_len/2;
        }
    }
    return s.substr(start, end-start+1);
}

/*2-Dynamic Programming*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len < 2) return s;
        vector<vector<int>>temp(len, vector<int>(len,0));
        int start = 0, end = 0;
        for(int i = 0; i < len; i++) temp[i][i] = 1;
        for(int n = 2; n <= len; n++){
            for(int i = 0; i <= len-n; i++){
                if(s[i] == s[n+i-1])
                    temp[i][n+i-1] = (temp[i+1][n+i-2] == n - 2)?n:1;
                else
                    temp[i][n+i-1] = max(temp[i+1][n+i-1], temp[i][n+i-2]);
                /*Saving and updating the start and end
		 * position of longest palindrome substring*/
		if(temp[i][n+i-1] > end-start+1){
                        start = i;
                        end = n+i-1;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};
