/* Time Complexity O(N) */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i+=2)  {
            if(nums[i] != nums[i+1]) return nums[i];
        }
        return nums[nums.size()-1];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(auto x:nums) res^=x;
        return res;
    }
};

/* Optimal the code by using Binary Search - Time Complexity O(logN) */
/* Following the requirements, the number of elements in vector has to be odd number.
if mid = (number_of_elements)/2, it will represent the number of elements in the
left and right of the mid. Go through 2 examples to get better understanding.

Ex1: total elements: 7 <=> 0 1 2   3    4 5 6 ==> the middle position is 3 <=> having
3 elements in the left and the right of the position 3. So, if num[3] = num[2], the target
number has to be on the right of the middle => move left as left = mid+1. In converse, it means
num[3] != num[2], and num[3] has to be euqal num[4], because if num[3] != num[2] and num[3] != num[4]
there has at least 3 numbers which appears only once. Consequently, the target number has to be on
the left ==> move right as right = mid-1.

Ex2: total elements: 9 <=> 0 1 2 3    4    5 6 7 8 ==> the middle position is 4 <=> having
4 elements in the left and the right of the position 4. */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(mid%2 == 0){
                if(nums[mid] == nums[mid-1]) right = mid-2;
                else left = mid;
            } else {
                if(nums[mid] == nums[mid-1]) left = mid+1;
                else right = mid-1;
            }
        }
        return nums[left];
    }
};

/* Continuing to optimize the code, still using BS */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while(left < right){
            mid = left + (right-left)/2;
            if(mid%2 != 0) mid+=1; // reducing the repetition of the code
            if(nums[mid] == nums[mid-1]) right = mid-2;
            else left = mid;
        }
        return nums[left];
    }
};
