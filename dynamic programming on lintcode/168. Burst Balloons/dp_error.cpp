// 错误的处理方式

class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2));
        vector<int> numss(n+2);
        
        numss[0] = numss[n+1] = 1;
        for(int i=1; i<=n; i++) {
            numss[i] = nums[i-1];
        }
        // 因为这种dp本质上是按区间长度递推的
        for(int i=0; i<=n; i++) {
            for(int j=i+1; j<=n+1; j++) {
                dp[i][j] = 0;
                for(int k=i+1; k<j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+numss[i]*numss[k]*numss[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};