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
