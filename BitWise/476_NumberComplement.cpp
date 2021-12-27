/*First approach*/
class Solution {
public:
    int findComplement(int num) {
        int count = 0, res = 0, remain = 0;
        while(num > 0){
            remain = num%2;
            if(remain == 0) remain = 1;
            else remain = 0;     
            res += remain*pow(2,count);
            count++;
            num /= 2;
        }
        return res;
    }
};

/* Example: 5 <=> 0000 0101 ==> ignore leading 0s ==> 101 ==> flipping it, we have: 010 <=> 2 */
class Solution {
public:
    int findComplement(int num) {
        int temp = 1, ret = 0;
        while(num != 0){
            //checking the last bit if it is 0 or 1, then flip it by using temp
            if( (num & 1) == 0) ret |= temp; 
            num >>=1;
            temp <<=1;// temp is used to keep track the position of bit we are checking in num
        }
        return ret;
    }
};
