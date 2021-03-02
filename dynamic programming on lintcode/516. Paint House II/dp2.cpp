/*   
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
        int min1, min2, id1, id2;
        for(int i=0; i<dp.size(); i++) {
            for(int j=0; j<costs[0].size(); j++) {
                if(i==0) {
                    dp[i][j] = 0;
                    continue;
                }
                if(id1 == j) {
                    dp[i][j] = min2 + costs[i-1][j];
                } else {
                    dp[i][j] = min1 + costs[i-1][j];
                }
                if(i==costs.size()) {
                    ans = min(ans, dp[i][j]);
                }
            }
            min1 = min2 = INT_MAX;
            for(int j=0; j<costs[0].size(); j++) {
                if(dp[i][j] < min1) {
                    min2 = min1;
                    id2 = id1;      // 这里虽然刚开始min1和id1都未定义，但是当找到次小值时min2和id2会再次赋值
                    min1 = dp[i][j];
                    id1 = j;
                } else {    // 这里处理了最小值和次小值相等的情况
                    if(dp[i][j] < min2) {
                        min2 = dp[i][j];
                        id2 = j;
                    }
                }
            }
        }
        return ans;
    } 
};