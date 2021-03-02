/*
    dp[n] = dp[i] && a[i]>=n-i (i为不小于n的正整数)
*/
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        vector<bool>dp(A.size(), false);
        dp[0] = true;
        for(int i=0; i<dp.size(); i++) {
            for(int j=i-1; j>=0; j--) {
                if(dp[j] && A[j]>=i-j) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[dp.size()-1];
    }
};