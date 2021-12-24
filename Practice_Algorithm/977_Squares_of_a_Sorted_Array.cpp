/*
Since the original array has been sorted, then if the
array just contains only positive or zero number, we
only take the square for each number. Otherwise, array
will have both negative and positive or even zero number.
However, after squaring, we gonna have two parts that are 
left part and right part always been sorted from right -> left
and left -> right. For example:
-4 -2 -1 0 3 10
16  4  1 0 9 100
<-------- ------>
   inc      inc
==> compare left part and right part
Note: if we use swap after comparing the nums[left] and nums[right]
it will have more complicated since after swaping, we need to keep track
what number from the left and right side to use for the next comparison.
So, use the new array to keep the max number will be easier.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &x:nums)
            x *= x;
        vector<int>res;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(nums[left] <= nums[right]){
                res.push_back(nums[right]);
                right--;
            }else {
                res.push_back(nums[left]);
                left++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*More optimal*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &x:nums)
            x *= x;
        vector<int>res(nums.size(),0);
        int left = 0, right = nums.size()-1, i = right;
        while(left <= right){
            if(nums[left] <= nums[right]){
                res[i] = nums[right];
                right--;
            }else {
                res[i] = nums[left];
                left++;
            }
            i--;
        }
        return res;
    }
};
