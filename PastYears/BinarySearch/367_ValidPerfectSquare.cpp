/* Assume a is a perfect square ==> a = b*b <=> a/b = b and a%b = 0
so, if a/b > b <=> a > b^2 ==> we need to increase the value of b, like b = b+1.
if a/b < b <=> a < b^2  ==> we need to decrease the value of b, like b = b-1.
Using the binary search, we will have the code as below */

class Solution {
public:
    bool isPerfectSquare(int num) {
        /*if(num == 1) return true;*/
        int left = 1, right = num;
        int mid;
        while(left <= right){
            mid = left + (right-left)/2;
            if(num/mid < mid) right = mid-1;
            else if ( num/mid > mid) left = mid+1;
            else if(num%mid == 0 && num/mid == mid) return true;
            else return false;
        }
        return false;
    }
};

/* The order crazy+funny solutions */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int left = 1, right = num;
        int mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(mid == left) return false;
            if(num/mid < mid) right = mid;
            else if ( num/mid > mid) left = mid;
            else if(num%mid == 0 && num/mid == mid) return true;
            else if(num/mid == mid && num%mid != 0) return false;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        int mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(num/mid < mid) right = mid;
            else if ( num/mid > mid){
                left = mid;
                break;
            }
            else if(num%mid == 0 && num/mid == mid) return true;
        }
        for(int i = left; i <= right; i++){
            if(num%i == 0 && num/i == i) return true;
        }
        return false;
    }
};
