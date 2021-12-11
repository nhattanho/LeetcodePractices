/*
Time complexity : O(n). Size of recursion tree can go upto n.
Space complexity : O(n). The depth of recursion tree can go upto n.
*/

class Solution {
public:
    int getways(int start, int n, vector<int>& dp){
        if(start == n) return 1;
        if(start > n) return 0;
        
        if(dp[start] != 0) return dp[start];
        
        dp[start] = getways(start+1, n, dp) + getways(start+2, n, dp);
        return dp[start];
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        getways(0, n, dp);
        return dp[0];
    }
};

/*
Let dp[i] is the number of ways to reach ith level

With (i-1) steps, we have one way to go to the ith level by using single step
With (i-2) steps, to reach ith level, we have to ways to do:
+ Use single step to reach (i-1) level first, then reach ith from i-1 level ==> with this way, we will have dp[i-1] ways already to reach ith level.
+ Use single of 2 steps to reach ith level. ==> use dp[i-2] <=> number of steps to reach i level from i-2 level
==> dp[i] = dp[i-1] + dp[i-2]
==>Need to find the base case with dp[1] and dp[0]
dp[2] = dp[0] + dp[1]
dp[1] -> dp[2] have 1 way ==> dp[1] = 1
dp[0] -> dp[2]:
dp[0]->dp[1]->dp[2]: already 1 way 
dp[0]->dp[2] : 1 ways
==> dp[0] = 1
*/
class Solution {
public:
    
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*Optimal Space based on above solution*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        int first = 1;
        int second = 1;
        int res = second;
        for(int i = 2; i <= n; i++){
            res = first+second;
            first = second;
            second = res;
        }
        return res;
    }
};
