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
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                dp[i][j] = INT_MAX;
                if(i>0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+grid[i][j]);
                }
                if(j>0) {
                     dp[i][j] = min(dp[i][j], dp[i][j-1]+grid[i][j]);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};