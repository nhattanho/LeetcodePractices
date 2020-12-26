class Solution {
public:
    int square(int n){
        int mod = 0, pre_mod = 0;
        while(n>0){
            mod = n%10;
            n = n/10;
            pre_mod += pow(mod,2);
        }
        return pre_mod;
    }
    bool isHappy(int n) {
        int low = square(n);
        int fast = square(low);
        while(low != fast){
            low = square(low);
            fast = square(square(fast));
        }
        if(low == 1) return true;
        return false;
    }
};
