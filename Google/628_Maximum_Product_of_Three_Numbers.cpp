class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        for(int i = 0; i < 3; i++){
            int temp = 1;
            for(int j = 0; j < i; j++){
                temp *= nums[j];
            }
            
            for(int h = nums.size()-3+i; h < nums.size(); h++){
                temp *= nums[h];
            }
            res = max(res, temp);
        }
        return res;
    }
};

/*
example we have:
amin1 amin2 ...... amax1 amax2 amax3

To compare max product of 3 number we just need to compare 
amin1*amin2*amax3 with amax1*amax2*amax3

Generally, we have 4 cases to compare:
amax1*amax2*amax3
amin1*amax2*amax3 ==> this is always < amax1*amax2*amax3
amin1*amin2*amax3
amin1*amin2*amin3 ==> this is always < amin1*amin2*amax3 and amax1*amax2*amax3
Since checking 5 cases below, we will see:
- - - ....-
- - - ....+
- - + ....+
- + + ....+
+ + + ....+
*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        cout << *(nums.begin()+3) << endl;
        sort(nums.begin(), nums.begin()+3);
        int res = INT_MIN;
        int max1 = nums[0], max2 = nums[1], max3 = nums[2];
        int min1 = nums[0], min2 = nums[1];
        for(int i = 3; i < nums.size(); i++){
            if(nums[i] > max3){
                max1 = max2;
                max2 = max3;
                max3 = nums[i];
            } else if(nums[i] > max2){
                max1 = max2;
                max2 = nums[i];
            } else if(nums[i] > max1){
                max1 = nums[i];
            }
            
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }else if (nums[i] < min2){
                min2 = nums[i];
            }
        }
        res = max(max1*max2*max3, min1*min2*max3);
        return res;
    }
};
