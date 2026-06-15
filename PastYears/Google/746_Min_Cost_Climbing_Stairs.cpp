/*
To do this question, we can assume dp[i] is the min cost to jump out of the ith position and go upto
i+1 or i+2 position. So, the total cost to jump out of (i+1)th position on is min(dp[i-1], dp[i]) + cost[i+1]
However, if i+1 is the last position, so the total cost will be min(dp[i-1] + cost[i+1], dp[i])
Since, at ith we can take single of 2 steps to reach out of the roof that over the (i+1)th position
==> no need to add the cost at i+1 position.
*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if( n == 2) return cost[0] > cost[1]?cost[1]:cost[0];

        vector<int>dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            if(i == n-1)
                dp[i] = min(dp[i-2]+cost[i], dp[i-1]);
            else 
                dp[i] = min(dp[i-2]+cost[i], dp[i-1]+cost[i]);
        }
        return dp[n-1];
    }
};


/*Optimize Space to O(1)*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if( n == 2) return cost[0] > cost[1]?cost[1]:cost[0];
      
        for(int i = 2; i < n; i++){
            if(i == n-1)
                cost[i] = min(cost[i-2]+cost[i], cost[i-1]);
            else 
                cost[i] = min(cost[i-2]+cost[i], cost[i-1]+cost[i]);
        }
        return cost[n-1];
    }
};
