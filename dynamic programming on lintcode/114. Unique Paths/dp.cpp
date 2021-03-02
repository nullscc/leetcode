/*
    dp[i][j] = dp[i-1][j] + dp[j][i-1];
*/

class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++) {
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};