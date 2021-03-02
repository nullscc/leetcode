/*
    dp[i][j]代表走到index为i, j有多少种可能
    当 obstacleGrid[i][j]==1 dp[i][j] = 0;
    当 i==0, j==0，dp[i][j] = 1;
    当 i==0，j!=0，dp[i][j] = dp[i][j-1];
    当 i!=0，j==0，dp[i][j] = dp[i-1][j];
    其他情况 dp[i][j] = dp[i][j-1] + dp[i-1][j];
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                if(!i && !j) {
                    dp[i][j] = 1;
                    continue;
                }
                if(!i) {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                if(!j) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};