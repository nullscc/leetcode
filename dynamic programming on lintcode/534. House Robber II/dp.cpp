/*
    这里是 516 问题的进一步复杂化
    将问题简化为两种情况:
    1. 考虑不偷第0栋房子
    2. 考虑不偷第n-1栋房子

    不偷第0栋房子情况(即dp[1]=0):
        dp[i] = max(dp[i-2]+A[i-1], dp[i-1])
                前一个代表偷到第i-1栋房子(第i-2自然就不能偷了)，后一个代表只偷到第i-2栋房子
        这里dp[i]代表偷到i-1栋房子最多能偷的
    
    不偷第n-1栋房子情况(即dp[n-1]=0，起始的时候从第n-1栋房子倒着偷):
        dp[i] = max(dp[i+2]+A[i], dp[i+1])
        这里dp[i]代表偷到i+1栋房子最多能偷的，即最后一个dp[i]为dp[0]，所以dp[0]代表最后一栋房子，所以现在的index刚好和base为0的对应上了
            即 dp[i+2]+A[i] 代表偷第i栋房子(自然dp[i+1]=0)的最大金额
               dp[i+1] 代表不偷第i栋房子的最大金额
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber2(vector<int> &A) {
        if(!A.size()) return 0;
        if(A.size() == 1) return A[0];
        // write your code here
        long long ans = 0;
        vector<long long>dp(A.size()+1);
        // 不偷第0栋房子的情况
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<dp.size(); i++) {
            dp[i] = max(dp[i-2]+A[i-1], dp[i-1]);
        }
        ans = max(ans, dp[A.size()]);
        
        // 不偷第n-1栋房子的情况
        dp[A.size()] = 0;
        dp[A.size()-1] = 0; // 这个就是代表不偷第n-1栋房子
        for(int i=A.size()-2; i>=0; i--) {
            dp[i] = max(dp[i+2]+A[i], dp[i+1]);
        }
        return max(ans, dp[0]);
    }
};