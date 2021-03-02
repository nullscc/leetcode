/*
    dp[i][1]代表选择打劫到编号位i-1为止的房子的最大金额
    dp[i][0]代表选择不打劫编号位i-1的房子的最大金额

    dp[i][1] = dp[i-1][0] + A[i-1];
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        vector<vector<long long>>dp(A.size()+1, vector<long long>(2));
        dp[0][0] = dp[0][1] = 0;
        for(int i=1; i<dp.size(); i++) {
            dp[i][1] = dp[i-1][0] + A[i-1];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[A.size()][0], dp[A.size()][1]);
    }
};