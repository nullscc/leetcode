/*
    dp[i][j]代表A截止到i-1，B截止到j-1，B在A中子序列个数
*/

class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1));
        for(int i=0; i<=S.size(); i++) {
            for(int j=0; j<=T.size(); j++) {
                if(j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                if(i==0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                if(S[i-1] == T[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        
        return dp[S.size()][T.size()];
    }
};