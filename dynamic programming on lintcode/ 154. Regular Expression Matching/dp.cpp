/*
    dp[i][j] = {
        dp[i-1][j-1]    如果p[j-1] != '*' 并且p[j-1]==‘.’或者s[i-1]==p[j-1]
        dp[i][j-2] || (dp[i-1][j] && (B[j-2]=‘.’ || B[j-2]=A[i-1]))     如果B[j-1]=‘*’
    }
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1));
        
        for(int i=0; i<=s.size(); i++) {
            for(int j=0; j<=p.size(); j++) {
                if(i==0 && j==0) {
                    dp[i][j] = true;
                    continue;
                }
                if(j==0) {
                    dp[i][j] = false;
                    continue;
                }
                
                if(p[j-1] != '*') {
                    if(i>0 && (p[j-1] == '.' || s[i-1] == p[j-1])) {
                        dp[i][j] = dp[i][j] || dp[i-1][j-1];
                    }
                } else {
                    if(j > 1) {
                        dp[i][j] = dp[i][j] || dp[i][j-2];
                        if(i>0 && (p[j-2] == '.' || s[i-1] == p[j-2])) {
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};