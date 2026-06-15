/* This problem just likes we need to find the maximum of sum of all
 * positive subtractions occurring in array. For example:
 * 7 1 3 6 8 In this case, 7 can not go to 1 (7->1) because the subtraction
 * is negative or the user can not have a profit with this transaction. So,
 * the transactions can be happened are: 1->3 + 3->6 + 6->8 or 1->6 +6->8,
 * or 1->8 => maximum profit = 7. Besides, we have to sell the stock before
 * buying again, so if we chose 1->6, we cannot go back to have 3->6. In the
 * other words, the days of transaction has to be going up. Going to next
 * circumstance, 1 5 3 6 4 We can have 1->5 + 5->6 or 1->3 + 3->6 or 1->6.
 * However,5>3 ==> 1->5 > 1->3, 3<5 ==> 3->6 > 5->6.
 * That why 1->6 = 1->5 + 5->6 < 1->5 + 3->6. From these main cases, we can
 * determine the maximum profit is equal the sum of positive subtraction
 * of two consecutive numbers in an array.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < prices.size()-1; i++)
            if(prices[i] < prices[i+1]) ans+= prices[i+1]-prices[i];
        return ans;
    }
};
