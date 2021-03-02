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
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2)));

        int old, now = 0;
        int a0, a1;
        for(int k=1; k<=strs.size(); k++) {
            old = now;
            now = 1 - old;
            a0 = a1 = 0;
            for(int i=0; i<strs[k-1].size(); i++) {
                if(strs[k-1][i] == '0') a0++;
                else a1++;
            }
            for(int i=0; i<=m; i++) {
                for(int j=0; j<=n; j++) {
                    dp[i][j][now] = dp[i][j][old];
                    if(i>=a0 && j>=a1) {
                        dp[i][j][now] = max(dp[i][j][now], dp[i-a0][j-a1][old]+1);
                    }
                }
            }
        }
        return dp[m][n][now];
    }
};