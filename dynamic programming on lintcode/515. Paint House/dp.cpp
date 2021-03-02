/*
    dp[n][0]中的n代表油漆完第n-1(0为base)栋房子且第n-1栋房子是红色的最小花费
    dp[n][1]中的n代表油漆完第n-1(0为base)栋房子且第n-1栋房子是蓝色的最小花费
    dp[n][2]中的n代表油漆完第n-1(0为base)栋房子且第n-1栋房子是绿色的最小花费

    即有
        dp[n][0] = min(dp[n-1][1]+costs[n-1][0], dp[n-1][2]+costs[n-1][0]);
*/

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        vector<vector<int>>dp(costs.size()+1, vector<int>(3));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i=1; i<dp.size(); i++) {
            dp[i][0] = min(dp[i-1][1]+costs[i-1][0], dp[i-1][2]+costs[i-1][0]);
            dp[i][1] = min(dp[i-1][0]+costs[i-1][1], dp[i-1][2]+costs[i-1][1]);
            dp[i][2] = min(dp[i-1][1]+costs[i-1][2], dp[i-1][0]+costs[i-1][2]);
        }
        return min(dp[costs.size()][0], min(dp[costs.size()][1], dp[costs.size()][2]));
    }
};