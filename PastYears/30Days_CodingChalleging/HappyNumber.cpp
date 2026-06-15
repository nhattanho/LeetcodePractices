/* Doesn't matter how the value of number big is, the sum of squares of
 * its digits is always the total of the squares of serial numbers from 0 to 9.
 * Besides, at any step we are calculating for the square, there exists one case
 * of the sum come up to a one-digit number. For example:
 * 749 = 7^2 + 4^2 + 9^2 = 146 ==> 1^2 +4^2 + 6^2 = 53 ==> 5^2 + 3^2 = 34 ==>
 * 3^2 + 4^2 = 25 ==> 2^2 + 5^2 = 29 ==> 2^2 + 9^2 = 85 ==> ...... = 20 ==>
 * 2^2  + 0^2 = 4 ==> 4^2 =16.........In this case, the one digit mentioned is 4.
 * So, to check if the number is happy or not, we narrow down this problem into
 * checking numbers from 1-9 is happy or not. Continuing the calculation as before,
 * we're going to realize that every number from 1 to 9 is unhappy except 1 and 7.
 * So, this way is how can we approach this solution as below - Time Complexity O(n)
 * and Space Complexity O(1)*/
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
                else return false;//break the cycle loop
            }
            n = pre_mod;
            pre_mod = 0;
        }
        return true;
    }
};

/* Also, "the operation of adding the squared digits of any natural number A,
 * a finite number of times is proved to transfe A either to unity or to one of a
 * set of eight numbers closed under the operation."(Arthur Porges)
 * https://fermatslibrary.com/s/a-set-of-eight-numbers*, so we can have another
 * approach. Space Complexity O(n)*/
class Solution {
public:
    bool isHappy(int n) {
        int mod = 0, pre_mod = 0;
        set<int>temp;
        while(true){
            while(n>0){
                mod = n%10;
                n = n/10;
                pre_mod += pow(mod,2);
            }
            if(pre_mod == 1) return true; //get the happy number
            /*if the same number has already existed, so its position is not the end */
            if(temp.find(pre_mod) != temp.end()) return false;//the same number occurs again ==> not happy
            temp.insert(pre_mod);
            n = pre_mod;
            pre_mod = 0;
        }
        return true;
    }

/* In the other hand, because the operation of adding square digits of every number will come to circle of
 * set of eight number, so we can use Floyd's cycle-finding algorith. For example:
 *    low  fast------
 *     |----|       |               ->42 
 *     v    v       v          ->145    ->20
 * 14->17->50->25->29->85->89->             ->4
 *                             ->58     ->16
 *                                  ->37
 Space Complexity O(n)*/
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
