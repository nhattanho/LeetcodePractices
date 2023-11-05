/*
Time complexity O(mn)
Space complexity O(m+n)
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> res(len1+len2, 0);

        int carry = 0;
        for(int i2 = len2-1; i2>= 0; i2--){
            int digit2 = num2[i2] - '0';
            carry = 0;
            for(int i1 = len1 - 1; i1 >= 0; i1--){
                int digit1 = num1[i1] - '0';
                int temp = digit1*digit2 + carry;
                
                carry = temp/10;
                temp = temp%10;

                res[i1+i2+1] += temp;
                
                carry += res[i1+i2+1]/10;
                res[i1+i2+1] = res[i1+i2+1]%10;
            }
            if (carry != 0) res[i2] = carry;
        }
        if(carry != 0) res[0] = carry;
        string ans = "";
        int  i = 0;
        while(res[i] == 0) i++;
        while(i < res.size()) ans+=to_string(res[i++]);
        
        return ans;
    }
};

/*
Optimized by pushing carry into the previous value in the array
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> res(len1+len2, 0);

        for(int i2 = len2-1; i2>= 0; i2--){
            int digit2 = num2[i2] - '0';
            for(int i1 = len1 - 1; i1 >= 0; i1--){
                int digit1 = num1[i1] - '0';
                int temp = digit1*digit2;

                res[i2+i1+1] += temp;
                res[i2+i1] += res[i2+i1+1]/10;
                res[i2+i1+1] %= 10;
            }
        }
        string ans = "";
        int  i = 0;
        while(res[i] == 0) i++;
        while(i < res.size()) ans+=to_string(res[i++]);
        
        return ans;
    }
};
