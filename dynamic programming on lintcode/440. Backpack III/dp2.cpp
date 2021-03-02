/*
    空间优化版
    
    dp[i][w]代表截止到编号为i-1的物品，拼出总重量为w的最大总价值(为-1代表不能拼出)
    dp[i][w] = max{dp[i-1][w], dp[i-1][w-A[i-1]]+V[i-1], dp[i-1][w-2*A[i-1]]+2*V[i-1], ...}
    
    因为 dp[i][w-A[i-1]] = max(dp[i-1][w-A[i-1]], dp[i-1][w-2*A[i-1]]+V[i-1], dp[i-1][w-3*A[i-1]]+2*V[i-1]);
    
    所以 dp[i][w] = max{dp[i-1][w], dp[i][w-A[i-1]]+V[i-1]};
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        vector<vector<int>> dp(2, vector<int>(m+1));
        
        dp[0][0] = 0;
        for(int i=1; i<=m; i++) {
            dp[0][i] = -1;
        }
        int ans = 0;
        int old, now=0;
        for(int i=1; i<=A.size(); i++) {
            old = now;
            now = 1 - old; 
            for(int w=0; w<=m; w++) {
                dp[now][w] = dp[old][w];
                if(w>=A[i-1] && dp[now][w-A[i-1]] != -1) {
                    dp[now][w] = max(dp[now][w], dp[now][w-A[i-1]]+V[i-1]);
                }
                ans = max(ans, dp[now][w]);
            }
        }
        return ans;
    }
};