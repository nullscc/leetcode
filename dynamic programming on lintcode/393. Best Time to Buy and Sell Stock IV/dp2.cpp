class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if(prices.size() < 2) return 0;
        
        if(k > (prices.size()/2)) {     // 如果 k > (prices.size()/2)，那么满足最大利润情况必为任意一个上升点都构成一次交易(一次买入一次卖出)
            int ans = 0;
            for(int i=1; i<prices.size(); i++) {
                if(prices[i]>prices[i-1]) ans += prices[i]-prices[i-1];
            }
            return ans;
        }

        int phase = 2*k;
        vector<vector<int>>dp(2, vector<int>(phase+1));
        int old, now = 0;
        for(int i=2; i<=prices.size(); i++) {
            old = now;
            now = 1-old;
            for(int j=0; j<phase+1; j++) {
                if(j == 0) {
                    dp[now][j] = 0;
                    continue;
                }
                if(j%2 == 0) {
                    dp[now][j] = max(dp[old][j], dp[old][j-1] + prices[i-1]-prices[i-2]);
                } else {
                    dp[now][j] = max(dp[old][j] + prices[i-1]-prices[i-2], dp[old][j-1]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<=phase; i+=2) {
            ans = max(ans, dp[now][i]);
        }
        return ans;
    }
};