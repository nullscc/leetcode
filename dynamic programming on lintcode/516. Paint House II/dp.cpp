/*
    本解法是正确的，但是会超时，dp2.cpp看怎么样不超时
    
    dp[i][j]表示染完编号位i-1房子并且编号i-1染成j颜色的最小花费
    
    dp[i][j] = min{dp[i-1][k]+costs[i-1][j]} (k!=j)
*/

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        if(!costs.size()) return 0;
        if(!costs[0].size()) return 0;
        // write your code here
        vector<vector<int>>dp(costs.size()+1, vector<int>(costs[0].size()));
        int ans = INT_MAX;
        for(int i=0; i<dp.size(); i++) {
            for(int j=0; j<costs[0].size(); j++) {
                if(i==0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = INT_MAX;
                for(int k=0; k<costs[0].size(); k++) {
                    if(k == j) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+costs[i-1][j]);
                }
                if(i==costs.size()) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    } 
};