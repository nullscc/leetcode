class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        // write your code here
        vector<vector<int>>dp(2, vector<int>(5));
        int old, now = 0;
        for(int i=2; i<=prices.size(); i++) {
            old = now;
            now = 1-old;
            for(int j=0; j<5; j++) {
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
        return max(max(dp[now][0], dp[now][2]),  dp[now][4]);
    }
};