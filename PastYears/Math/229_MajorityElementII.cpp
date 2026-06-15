//A Linear Time Majority Vote Algorithm
//http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.htmlvim 
/*Solution: assume we have:
number a with frequency > n/3
number b with frequency > n/3
number c with frequency > n/3 ==> frequency(a,b,c) > n ==> reject
so with the array has n numbers, there is maximum of two number which can have the frequency > n/3.
These are (a,b) or (a,c) or (b,c) or only a, b, or c
*/
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int num1 = 0, num2 = 0, vote1 = 0, vote2 = 0;

	    //Finishing the for loop help us guess two numbers that can have the frequency > n/3
            for(auto x:nums){
                if(num1 == x) vote1++;
                else if(num2 == x) vote2++;
                else if(vote1 == 0){ num1 = x; vote1 = 1; }
                else if(vote2 == 0){ num2 = x; vote2 = 1; }
                else{ vote1--; vote2--; }
            }

	    // Re-checking to make sure we have true number
            vote1 = 0; vote2 = 0;
            for(auto x:nums){
                if( x == num1) vote1++;
                else if (x == num2) vote2++;
            }
            vector<int>res;
            if(vote1 > nums.size()/3) res.emplace_back(num1);
            if(vote2 > nums.size()/3) res.emplace_back(num2);
            return res;
        }
};
/*For example: arr = { 1,2,4,2,1,1,2,1,3,4,1}
number 	frequency
1	5
2	3
3	1
4	2

So, if we pick 1 and 2 for the first time, then, after n times in the loop, 
two numbers still exist is 1 and 2, because they have a bigger frequency than others
After that, rechecking again to get 1.*/

