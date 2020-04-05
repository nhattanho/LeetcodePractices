/* Time Complexity O(n), Space O(1)
 * Remark the disappeared number like x by using it as a position of the array.
 * So, the value at array[x-1] won't be change anything if we do the same thing
 * for the other number that exists in the array. For example:
 * position:  [0] [1] [2] [3] [4] [5] [6] [7]
 * array:      4   3   2   7   8   2   3   1
 * Because 5&6 are numbers disappeared, arr[5-1]&arr[6-1] will still kepp its
 * value as before even though we have any calculation on arr[position] like
 * arr[4-1], arr[3-1], or any number has appeared already in the array.*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans;
        for(auto x:nums)
            if(nums[abs(x)-1] > 0) nums[abs(x)-1] *= -1;//make the change
        for(int i = 0; i < len; i++)
            if(nums[i] > 0) ans.push_back(i+1);//get the disappeared numbers
        return ans;
    }
};
