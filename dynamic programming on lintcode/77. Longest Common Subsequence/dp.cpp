/* 
    dp[i][j]代表A中以i-1结尾的字符串和B中以j-1结尾的最长公共子序列的
*/

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1));;
        for(int i=0; i<=A.size(); i++) {
            for(int j=0; j<=B.size(); j++) {
                if(!i || !j) {
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};