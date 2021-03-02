/*
    dp[i][1]代表选择打劫到编号位i-1为止的房子的最大金额
    dp[i][0]代表选择不打劫编号位i-1的房子的最大金额

    dp[i][1] = dp[i-1][0] + A[i-1];
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        long long p, q, pre_p, pre_q;
        pre_p = pre_q = 0;
        for(int i=1; i<A.size()+1; i++) {
            q = pre_p + A[i-1];
            p = max(pre_p, pre_q);
            pre_q = q;
            pre_p = p;
        }
        return max(p, q);
    }
};