class Solution {
public:
    bool isHappy(int n) {
        int mod = 0, pre_mod = 0;
        while(true){
            while(n>0){
                mod = n%10;
                n = n/10;
                pre_mod += pow(mod,2);
            }
            if(pre_mod < 10){
                if(pre_mod == 1 || pre_mod == 7) return true;
                else return false;
            }
            n = pre_mod;
            pre_mod = 0;
        }
        return true;
    }
};
