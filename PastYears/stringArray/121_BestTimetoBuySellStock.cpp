/* Time complexity O(n),space complexity O(1) */

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int len = p.size();
        int res = 0;// maximum profit
        int pos = 0; // for the less number
        
        for(int i = 0; i < len; i++){
            if(p[i] < p[pos]) pos = i;
            else res = max(res, p[i] - p[pos]);
        }
        
        return res;
    }
};
