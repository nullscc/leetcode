/*
    dp[i][j]代表截止到s1的i-1,s2的j-1构成了截止到s3的i+j-1
    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
*/

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        
        dp[0][0] = true;
        for(int i=1; i<=s1.size(); i++) {
            if(s1[i-1] != s3[i-1]) break;
            dp[i][0] = true;
        }
        for(int i=1; i<=s2.size(); i++) {
            if(s2[i-1] != s3[i-1]) break;
            dp[0][i] = true;
        }
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};