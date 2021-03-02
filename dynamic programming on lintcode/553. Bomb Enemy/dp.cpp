/*
    对于向上炸
    如果是0 up[i] = up[i-1]
    如果是e up[i] = up[i-1]+1
    如果是w up[i] = 0
*/

class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    
    int maxKilledEnemies(vector<vector<char>> &grid) {
        if(!grid.size()) return 0;
        if(!grid[0].size()) return 0;
        // write your code here
        vector<vector<int>>up(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>down(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>left(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>right(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>ans(grid.size(), vector<int>(grid[0].size()));
        int res = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(i==0) {
                    if(grid[i][j] == '0') up[i][j] = 0;
                    if(grid[i][j] == 'W') up[i][j] = 0;
                    if(grid[i][j] == 'E') up[i][j] = 1;
                } else {
                    if(grid[i][j] == '0') up[i][j] = up[i-1][j];
                    if(grid[i][j] == 'W') up[i][j] = 0;
                    if(grid[i][j] == 'E') up[i][j] = up[i-1][j]+1;
                }
                ans[i][j] += up[i][j];
            }
        }
        for(int i=grid.size()-1; i>=0; i--) {
            for(int j=0; j<grid[0].size(); j++) {
                if(i==grid.size()-1) {
                    if(grid[i][j] == '0') down[i][j] = 0;
                    if(grid[i][j] == 'W') down[i][j] = 0;
                    if(grid[i][j] == 'E') down[i][j] = 1;
                } else {
                    if(grid[i][j] == '0') down[i][j] = down[i+1][j];
                    if(grid[i][j] == 'W') down[i][j] = 0;
                    if(grid[i][j] == 'E') down[i][j] = down[i+1][j]+1;
                }
                ans[i][j] += down[i][j];
            }
        }
        for(int j=0; j<grid[0].size(); j++) {
            for(int i=0; i<grid.size(); i++) {
                if(j==grid[0].size()-1) {
                    if(grid[i][j] == '0') left[i][j] = 0;
                    if(grid[i][j] == 'W') left[i][j] = 0;
                    if(grid[i][j] == 'E') left[i][j] = 1;
                } else {
                    if(grid[i][j] == '0') left[i][j] = left[i][j-1];
                    if(grid[i][j] == 'W') left[i][j] = 0;
                    if(grid[i][j] == 'E') left[i][j] = left[i][j-1]+1;
                }
                ans[i][j] += left[i][j];
            }
        }
        for(int j=grid[0].size()-1; j>=0; j--) {
            for(int i=0; i<grid.size(); i++) {
                if(j==grid[0].size()-1) {
                    if(grid[i][j] == '0') right[i][j] = 0;
                    if(grid[i][j] == 'W') right[i][j] = 0;
                    if(grid[i][j] == 'E') right[i][j] = 1;
                } else {
                    if(grid[i][j] == '0') right[i][j] = right[i][j+1];
                    if(grid[i][j] == 'W') right[i][j] = 0;
                    if(grid[i][j] == 'E') right[i][j] = right[i][j+1]+1;
                }
                ans[i][j] += right[i][j];
                if(grid[i][j] == '0') res = max(ans[i][j], res);
            }
        }
        return res;
    }
};