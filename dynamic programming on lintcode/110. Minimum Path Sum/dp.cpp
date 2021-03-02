/*
    dp[i][j]代表到grid[i][j]的最小路径和

    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        if(!grid.size()) return 0;
        if(!grid[0].size()) return 0;
        // write your code here
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for(int i=1; i<grid.size(); i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1; i<grid[0].size(); i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i=1; i<grid.size(); i++) {
            for(int j=1; j<grid[0].size(); j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};