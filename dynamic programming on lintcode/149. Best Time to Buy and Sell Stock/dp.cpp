/*
    dp[i]代表在第i天卖(base为0)

    dp[i] = prices[i] - prices[k] (其中k为到index为止的最小值)
*/
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int ans = 0, cur;
        int min = prices[0];
        for(int i=0; i<prices.size(); i++) {
            if(prices[i]<min) {
                min = prices[i];
            }
            cur = prices[i] - min;
            ans = max(cur, ans);
        }
        return ans;
    }
};