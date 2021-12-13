/*Refer:
https://www.youtube.com/watch?v=YyHmAEQ6y6Q
https://www.youtube.com/watch?v=SuM12LERW_M
https://leetcode.com/problems/delete-and-earn/discuss/1391592/c%2B%2B-Solution-oror-House-Robbing-Problem-oror-No-to-adjacent-elements
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>sum;
        
        for(auto num: nums)
            sum[num] += num;
        int dp[10001] = {0};
        dp[0] = 0;
        dp[1] = sum[1];
        for(int i = 2; i < 10001; i++){
            dp[i] = max(dp[i-1], dp[i-2] + sum[i]);
        }
        return dp[10000];
    }
};

/*Reduce space though still have 0(N) for space*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>sum;
        
        for(auto num: nums)
            sum[num] += num;
        
        for(int i = 2; i < 10001; i++){
            sum[i] = max(sum[i-1], sum[i-2] + sum[i]);
        }
        return sum[10000];
    }
};
