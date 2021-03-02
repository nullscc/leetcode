/*
    dp[i][j][w]：s1中以i开头长度为w的字符能否经过变换成为s2中以j开头长度为w的字符串

    dp[i][j][w] = OR(1=<k<=w-1) {dp[i][j][k] && dp[i+k][j+k][w-k]}      // 代表对应的两段没有经过交换
                            OR
                  OR(1=<k<=w-1) {dp[i][j+w-k][k] && dp[i+k][j][w-k]}    // 代表对应的两段经过交换
*/

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        // write your code here
        int n = s1.size();
        if(n != s2.size()) return false; 
        
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1)));
        for(int w=1; w<=n; w++) {
            for(int i=0; i<=n-w; i++) {
                for(int j=0; j<=n-w; j++) {
                    if(w == 1) {
                        dp[i][j][w] = s1[i]==s2[j]?true:false;
                        continue;
                    }
                    int nochange = false;
                    int change = false;
                    for(int k=1; k<w; k++) {
                        if(dp[i][j][k] && dp[i+k][j+k][w-k]) {
                            nochange = true;
                        }
                        if(dp[i][j+w-k][k] && dp[i+k][j][w-k]) {
                            change = true;
                        }
                        if(nochange || change) break;
                    }
                    dp[i][j][w] = change || nochange;
                }
            }
        }
        return dp[0][0][n];
    }
};