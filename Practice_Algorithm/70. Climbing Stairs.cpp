public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}

/*BackTrack solution*/
class Solution {
    int count = 0;
    public int climbStairs(int n) {//n=3
        if(n == 0) return ++count;
        if(n<0) return count;
        
        int remain = 0;
        for(int i = 1; i < 3; i++){
            remain = climbStairs(n-i);
        }
        return remain;
    }
}

/*Optimize BackTrack*/
class Solution {
    int count = 0;
    public int climbStairs(int n) {//n=3
        if(n == 1 || n== 0) return 1;
        return (climbStairs(n-1) + climbStairs(n-2)); //==> based on this makes us think about the dp
    }
}

/*DP solution*/
class Solution {
    int count = 0;
    public int climbStairs(int n) {//n=3
        if(n == 1) return 1;
        int[]dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}

/*Continue optimizing the space by using only 3 variable*/
class Solution {
    int count = 0;
    public int climbStairs(int n) {//n=3
        if(n == 1) return 1;
        int first = 1;
        int second = 1;
        int third = 0;
        for(int i = 2; i <=n; i++){
            third = first+second;
            first = second;
            second = third;
        }
        return third;
    }
}
