/*
    dp[j]代表长度为j的序列可以构成多少中不同的二叉树，由于每个节点值不同，所以dp[j]与具体的序列值无关
    dp[j] = sum of(dp[i-1]*dp[j-i])  (i>=1 && i<=j) 代表从长度为j的序列中随便选取一个为根节点
            dp[i-1]为左子树不同二叉树个数
            dp[j-i]为右子树不同二叉树个数
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int j=2; j<=n; j++) {
            for(int i=1; i<=j; i++) {
                dp[j] += dp[i-1]*dp[j-i];
            }
        }
        return dp[n];
    }
};