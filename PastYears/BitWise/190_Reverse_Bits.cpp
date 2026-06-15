class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>res;
        int count = 32;
        while(count > 0){
            // if ((n&1) == 0) res.push_back(0);
            // else res.push_back(1); 
            res.push_back((n&1));
            n>>=1;
            count--;
        }
        uint32_t val = 0;
        for(int i = 0; i< res.size(); i++){
            val += res[i]*pow(2, res.size()-1 - i);
        }
        return val;
    }
};

/*Optimal Solution 1*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t check_bit = 1, res = 0;
        uint32_t set_bit = 0x80000000; 
        while(n != 0){
            if( (n&check_bit) == 1) res |= set_bit;
            set_bit >>= 1;
            n >>= 1;
        }
        return res;
    }
};

/*Optimal Solution 2*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t check_bit = 1, move_left = 31, res = 0;
        while(n != 0){
            res += (n&check_bit) << move_left;
            n >>= 1;
            move_left--;
        }
        return res;
    }
};
