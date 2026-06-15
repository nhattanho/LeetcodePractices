class Solution {
public:
    
    void reverse_string(string &s, int start, int len){
        reverse(s.begin()+start, s.begin()+start+len);
    }
    
    string reverseStr(string s, int k) {
        /*
         len < k => reverse all 
         k <= len < 2k => reverse k + left rest origianl
        */
        int len = s.length();
        int jump = 2*k;
        int times = len/jump;
        int remain = len%jump;
        
        for(int i = 0; i < times; i++){ /*times*/
            reverse_string(s, jump*i, k);/*k ==> Time complexity: times*k ~ len <=> 0(n)*/
        }
        
        if(remain < k) reverse_string(s, jump*times, remain);
        else reverse_string(s, jump*times, k);
        return s;
    }
};
