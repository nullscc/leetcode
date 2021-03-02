/*
    滚动数组版本
    
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
        vector<vector<int>>dp(2, vector<int>(grid[0].size()));
        int old=0, now=1;
        for(int i=0; i<grid.size(); i++) {
            old = now;
            now = 1-old;
            for(int j=0; j<grid[0].size(); j++) {
                if(i==0 && j==0) {
                    dp[now][j] = grid[i][j];
                    continue;
                }
                
                dp[now][j] = INT_MAX;
                if(i>0) {
                    dp[now][j] = min(dp[now][j], dp[old][j]+grid[i][j]);
                }
                if(j>0) {
                     dp[now][j] = min(dp[now][j], dp[now][j-1]+grid[i][j]);
                }
            }
        }
        return dp[now][grid[0].size()-1];
    }
};