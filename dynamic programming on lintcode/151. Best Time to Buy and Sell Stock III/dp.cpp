/*
    将买股票分为5个阶段：
    阶段0 一支股票都还没买
    阶段1 买了第一支股票
    阶段2 卖了第一支股票
    阶段3 买了第二支股票
    阶段4 卖了第二支股票

    dp[i][j]代表在第i-1(base为0)天处于阶段j的最大利润(这个最大利润有两种含义：1. 如果手里没有股票，利润就是手上的已经赚到的钱，2. 如果有股票，将手里的股票卖掉能得到的利润，因为最大的利润必是手里没有股票了，所以这样定义没问题)
    阶段0    dp[i][0] = 0    
    阶段1 3: dp[i][j] = max(dp[i-1][j] + prices[i-1]-prices[i-2], dp[i-1][j-1]);
                            前一个代表第i-2天就在阶段j，即持有，后一个代表第i-1天买入(这里定义买入不亏钱，因为前面是定义的持有情况是需要将利润逐天累加的，所以当处于阶段1 3的意义在于假设在这天卖出的利润)
    阶段2 4: dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i-1]-prices[i-2]);
                            前一个代表第i-2天就在阶段j，后一个代表第i-1天卖出
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(!prices.size()) return 0;
        // write your code here
        vector<vector<int>>dp(prices.size()+1, vector<int>(5));
        for(int i=2; i<dp.size(); i++) {
            for(int j=0; j<5; j++) {
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
        return max(max(dp[prices.size()][0], dp[prices.size()][2]),  dp[prices.size()][4]);
    }
};