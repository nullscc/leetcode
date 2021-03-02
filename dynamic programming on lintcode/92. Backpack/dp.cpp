/*
    dp[i][w]表示一直到编号为i-1的物品能是否能凑出重量为w(w小于背包容量)的物品
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<vector<bool>> dp(A.size()+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i=1; i<=m; i++) {
            dp[0][i] = false;
        }
        for(int i=1; i<=A.size(); i++) {
            for(int w=0; w<=m; w++) {
                dp[i][w] = dp[i-1][w];
                if(w >= A[i-1]) {
                    dp[i][w] = dp[i][w] || dp[i-1][w-A[i-1]];
                }
            }
        }
        
        int ans;
        for(int i=m; i>=0; i--) {
            if(dp[A.size()][i]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};