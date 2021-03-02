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
        int old, now = 0;
        for(int k=1; k<=strs.size(); k++) {
            old = now;
            now = 1 - old;
            for(int i=0; i<=m; i++) {
                for(int j=0; j<=n; j++) {
                    dp[i][j][now] = dp[i][j][old];
                    if(i>=A[k-1] && j>=B[k-1]) {
                        dp[i][j][now] = max(dp[i][j][now], dp[i-A[k-1]][j-B[k-1]][old]+1);
                    }
                }
            }
        }
        return dp[m][n][now];
    }
};