/*Time O(logn)*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int count = 0;
        while(n!=0){
            if(n & 1) count++;
            n >>= 1;
        }
        return count==1?true:false;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0|| n<0) return false;
        while(n%2 == 0) n/=2;
        return  n == 1;
    }
};
/*Time O(1)*/
