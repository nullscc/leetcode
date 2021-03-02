/*
    简化一下
    dp[i]代表选择打劫到编号位i-1位置的房子(不管选择打劫与否)的最大金额

    dp[i] = max(dp[i-2]+A[i-1], dp[i-1])
            前一个代表偷到第i-1栋房子(第i-2自然就不能偷了)，后一个代表只偷到第i-2栋房子
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        vector<long long>dp(A.size()+1);
        dp[0] = 0;
        dp[1] = A[0];
        for(int i=2; i<dp.size(); i++) {
            dp[i] = max(dp[i-2]+A[i-1], dp[i-1]);
        }
        return dp[A.size()];
    }
};