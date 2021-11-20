class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int>set;
        long sum1 = 0;
        for(auto x: nums) sum1 += x;
        
        long sum2 = 0;
        for(auto x : nums) set.insert(x);
        for(auto x: set) sum2 += x;
        
        return (sum2*3 - sum1)/2;
        
    }
};

/* Follow:
https://leetcode.com/problems/single-number-ii/discuss/689932/C%2B%2B-EASIEST-CODE-WITH-EXPLANATION-AND-FOLLOW-UP
Let the input be [2,2,2,3]
We iterate vertically through the input all along 32 times (integer is represented in 32 bits)
2-> 1 0
2-> 1 0
2-> 1 0
3-> 1 1

We find the sum of each ith vertical level. (i in range 0 to 31)

If the sum is divisible by 3 then the ith bit in the single occuring number is 0 ( since each number except one occurs three times so the bitsum will be 3(some constant)

if the sum is not divisible by three then the ith bit in the single occuring number is 1 (since the bitsum in this case will be 3(constant) +1

Since the ith bit is set in the single occuring number, you have to build the number by setting the ith bit when the bitsum in ith place is not divisible by three.
*/

/*Or
https://leetcode.com/problems/single-number-ii/discuss/700046/Single-Number-II-Easy-to-Understand-(Language-C%2B%2B)
Basic Idea

We are given an array where every integer, except one, occurs thrice. Therefore, at every bit position, there is an odd bit while all other bits occur as multiples of 3.
The following example will make this clearer.

Take the input array : [2, 2, 2, 4, 4, 4, 5]

A B C
0 1 0 ~ 2
0 1 0
0 1 0
1 0 0 ~ 4
1 0 0
1 0 0
1 0 1 ~ 5

At bit position A : 3 occurences of '0' + 3 occurences of '1' + 1 occurence of '1'
At bit position B : 3 occurences of '1' + 3 occurences of '0' + 1 occurence of '0'
At bit position C : 6 occurences of '0' + 1 occurence of '1'

Therefore, at each bit position, we have bits that occur in multiples of 3, and one lone bit.
So, if we add up the bits at a given position as sum, and find the remainder when sum is divided by 3, we get the left over bit.

For the bits at A, sum = 4 : 4 % 3 = 1
For the bits at B, sum = 3 : 3 % 3 = 0
For the bits at C, sum = 1 : 1 % 3 = 1
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans = 0;
        for(int i = 0; i < 32; i++){
            int sumbit = 0;
            for(int x : nums){
                sumbit += ((x>>i)&1);
            }
            sumbit %= 3;
            ans += sumbit*pow(2,i);
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans = 0;
        for(int i = 0; i < 32; i++){
            int sumbit = 0;
            for(int x : nums){
                //move number to the right i bits, then and with 1 to check and get value of the ith column is 1 or 0
                sumbit += ((x>>i)&1);
            }
            /*sum of bits of ith COLUMN divisible for 3 
            ==> bit = 0, otherwise, bit = 1 ==> OR with 1 
            at ith COLUMN*/
            if(sumbit%3)
                ans |= (1<<i); // move 1 to the left i bits to set bit 1 for column ith
        }
        return ans;
    }
};
