/*
1 2 3
4 5 6
7 8 9
m is #rows, n is #cols
In this case get m = n = 3
could be represented:

                               root                     level 0
                             /   |   \
                            1    2    3                 level 1
                           / | \ ... / | \
                          4  5  6   4  5  6             level 2
                        / | \          | / | \     
                       7  8  9 .... .... 7 8  9         level 3
+For the left branch seen from the root:
 Level 2: n + n + n + .... + n ==> nxn = n^2
 Level 1: n^2 + n^2 + .... + n^2 = nxn^2 = n^3
 ==> In general, the time complexity will be n^m
 
O(cols ^ rows)
Used dfs go from the top-> bottom, then from left to right
*/
class Solution {
private:
    int res = INT_MAX;
public:
    
    void findMax(vector<vector<int>>mat, int target, int r, int sum){
        for(int i = 0; i < mat[0].size(); i++){
            if (r == mat.size()) {
                res = min(res, abs(target-sum));
                return;
            }
            int temp = sum + mat[r][i];
            findMax(mat, target, r+1, temp);
        }
        
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();
        findMax(mat, target, 0, 0);
        return res;
    }
    
};

/*
This is hard to come up with the dp solution, then I would suggest we try the 
bruteforce above first, then we can optimize later. 
We can optimize if:
+ we calculate the sum at each row, then get the different distance by subtracting the target, 
then, if the sum at each row are equal, mean if has been calculate before that, can skip.
examp:
1  2  3
4  2  1
4  5  6
==> if we start from 1, then at second row, we will have 1 + 4 = 5, then continue
Then we go back the first row and process for number 3, we wiil have the addition 3+2= 5 
==> we can stop, since at the second row, sum = 5 has been known as the previous step.

+ In the same row has the duplicated number
*/
class Solution {
public:
    int dp[71][4901];
    int findMin(vector<vector<int>>mat, int target, int r, int sum){
        
        if(r == mat.size()) return abs(target - sum);
        
        if(dp[r][sum] == -1) { 
            int value = INT_MAX;
            for(int i = 0; i < mat[0].size(); i++){
                if (i != 0 && mat[r][i] == mat[r][i-1]) continue;
                value = min(value, findMin(mat, target, r+1, sum+mat[r][i]));
            }
            return dp[r][sum] = value;
        } else return dp[r][sum]; 
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        int rows = mat.size();
        int cols = mat[0].size();
        return findMin(mat, target, 0, 0);
    }
    
}
