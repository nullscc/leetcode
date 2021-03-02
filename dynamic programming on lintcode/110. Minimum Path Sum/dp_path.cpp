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
        vector<vector<int>> pi(grid.size(), vector<int>(grid[0].size())); // 0 从自身来，1从上面来，2从左面来
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                pi[i][j] = 0;
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
                if(dp[i][j] == dp[i-1][j]+grid[i][j]) {
                    pi[i][j] = 1;
                }
                if(dp[i][j] == dp[i][j-1]+grid[i][j]) {
                    pi[i][j] = 2;
                }
            }
        }
        int cur_i = grid.size()-1, cur_j = grid[0].size()-1;
        while(pi[cur_i][cur_j]) {
            if(pi[cur_i][cur_j] == 1) {
                cout<<cur_i<<","<<cur_j;
                cur_i = cur_i-1;
            } else {
                cout<<cur_i<<","<<cur_j;
                cur_j = cur_j-1;
            }
            if(pi[cur_i][cur_j]) cout<<"<--";
        }
        cout<<"<--0,0"<<endl;
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};