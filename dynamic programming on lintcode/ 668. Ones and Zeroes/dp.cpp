/*
    dp[i][j][k]代表截止到strs中的k-1下标(包括)用i个0，j个1最多能组成strs[0...k-1]中的几种
    dp[i][j][k] = max(dp[i][j][k-1], dp[i-A[k-1]][j-B[k-1]][k-1]+1);
*/

class Solution {
public:
    /**
     * @param strs: an array with strings include only 0 and 1
     * @param m: An integer
     * @param n: An integer
     * @return: find the maximum number of strings
     */
    int findMaxForm(vector<string> &strs, int m, int n) {
        // write your code here
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size()+1)));
        vector<int> A(strs.size());
        vector<int> B(strs.size());
        for(int i=0; i<strs.size(); i++) {
            for(int j=0; j<strs[i].size(); j++) {
                if(strs[i][j] == '0') {
                    A[i]++;
                } else {
                    B[i]++;
                }
            }
        }
        for(int k=0; k<=strs.size(); k++) {
            for(int i=0; i<=m; i++) {
                for(int j=0; j<=n; j++) {
                    if(k==0) {
                        dp[i][j][k] = 0;
                        break;
                    }
                    dp[i][j][k] = dp[i][j][k-1];
                    if(i>=A[k-1] && j>=B[k-1]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-A[k-1]][j-B[k-1]][k-1]+1);
                    }
                }
            }
        }
        return dp[m][n][strs.size()];
    }
};