class Solution {
public:
    
    // -7 -6 0 0 1 1 1 2 2 6 9 ==> sum = 9 ==> s1 = s2 = s3 = 3
    bool canThreePartsEqualSum(vector<int>& arr) {
        int len = arr.size();
        int sum = 0;
        for(auto x: arr){
            sum += x;
        }
        if(sum %3 != 0) return false;
        sum = sum/3;
        int temp = 0, count = 0;
        for(auto x: arr){
            temp += x;
            if(temp == sum) {
                temp = 0;
                count++;
            }
        }
        return count >= 3?true:false; // count > 3 for edge case: the total sum of array = 0
    }
};
