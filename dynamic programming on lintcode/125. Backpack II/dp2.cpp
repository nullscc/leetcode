/*
    dp[i][w]代表截止到编号为i-1的物品，拼出总重量为w的最大总价值(为-1代表不能拼出)
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<vector<int>> dp(A.size()+1, vector<int>(m+1));
        dp[0][0] = 0;
        for(int i=1; i<=m; i++) {
            dp[0][i] = -1;
        }
        int ans = INT_MIN;
        for(int i=1; i<=A.size(); i++) {
            for(int w=0; w<=m; w++) {
                dp[i][w] = dp[i-1][w];
                if(w>=A[i-1] && dp[i-1][w-A[i-1]] != -1) {
                    dp[i][w] = max(dp[i][w], dp[i-1][w-A[i-1]]+V[i-1]);
                }
                ans = max(ans, dp[i][w]);
            }
        }
        return ans;
    }
};