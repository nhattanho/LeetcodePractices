class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mark = p[0];
        int profit = 0;
        for(int i = 0; i < p.size(); i++){
            if(mark > p[i]) mark = p[i];
            else profit = max(profit, p[i]-mark);
        }
        return profit;
    }
};
