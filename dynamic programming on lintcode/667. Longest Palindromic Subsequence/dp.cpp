/*
    dp[i][j] = max{dp[i+1][j], dp[i][j-1], dp[i+1][j-1]+2}
*/

class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        // write your code here
        int n = s.size();
        if(n == 0) return 0;

        if(n == 1) return 1;
        vector<vector<int>> dp(n, vector<int>(n));
        
        // len == 1
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
        }
        
        // len == 2
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            } else {
                dp[i][i+1] = 1;
            }
        }
        
        for(int len=3; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i+len-1;
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if(s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
                }
            }
        }
        return dp[0][n-1];
    }
};