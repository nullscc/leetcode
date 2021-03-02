/*
    与 151. Best Time to Buy and Sell Stock III 同类型问题

    不完全版本，因为没处理:
    1. k > prices/2 等同于任意次的情况
    2. 在天数过多的情况下内存超限制

    完全版本见dp2.cpp
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        if(prices.size() < 2) return 0;
        int phase = 2*k;
        // write your code here
        vector<vector<int>>dp(prices.size()+1, vector<int>(phase + 1));
        for(int i=2; i<dp.size(); i++) {
            for(int j=0; j<phase+1; j++) {
                if(j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if(j%2 == 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i-1]-prices[i-2]);
                } else {
                    dp[i][j] = max(dp[i-1][j] + prices[i-1]-prices[i-2], dp[i-1][j-1]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<=phase; i+=2) {
            ans = max(ans, dp[prices.size()][i]);
        }
        return ans;
    }
};