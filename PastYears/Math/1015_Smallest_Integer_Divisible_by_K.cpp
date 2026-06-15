/*
N = N*10 + 1
remainder = N%K
Since the remainder and N have the same remainder of K, it OK to use remainder instead of N

We can use:
N = remainder*10 + 1
remainder = N%K
to avoid the overflow

***Prove:***
Firstly, we have:
N = old_N*10 + 1
remainder = N%K ==> N = kx + remainder, x is an integer number

==> new_N = (kx+remainder)10 + 1 = (10kx + 10remainder + 1)
==> new_remainder = (10kx + 10remainder + 1)%k = ( 10remainder + 1)%k (since 10kx%k = 0)

Because the main purpose needs to check the remainder, new_N can be represented by 10remainder + 1 instead of using 10kx + 10remainder + 1

Then, finally, we end up with:

N = 10*remainder + 1
remainder = N%k
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0) return -1;
        int res = 0, power = 0, remain = 0;
        unordered_map<int,int>check;
        while(true){
            res = res*10 + 1;
            remain = res%k;
            if(remain == 0) return power+1;
            if(check.count(remain)) break;
            check[remain]++;
            power++;
        }
        return -1;
    }
};
            ||
            ||
            \/
/*
if the while-loop continues forever, the remainder repeats. 
Also, if remainder repeats, then it gets into a loop. 
Hence, the while-loop is endless if and only if the remainder repeats.
*/              
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0) return -1;
        int res = 0, power = 0, remain = 0;
        unordered_map<int,int>check;
        while(true){
            res = remain*10 + 1;
            remain = res%k;
            if(remain == 0) return power+1;
            if(check.count(remain)) break;
            check[remain]++;
            power++;
        }
        return -1;
    }
};

/*More optimal*/
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0) return -1;
        int res = 0, power = 0, remain = 0;
        for(int i = 1; i <= k; i++){
            remain = (remain*10+1)%k;/*remain will be in range of [1,k], if remain = k ==> divisible, if not, the remainder is repeated <=> has no remain%k = 0*/
            if(remain == 0) return i;
        }
        return -1;
    }
};
