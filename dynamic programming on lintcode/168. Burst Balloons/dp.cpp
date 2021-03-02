/*
    dp[i][j]为扎破区间(i, j)内的所有气球获得的最大金币数(不包括i，j)
    
    dp[i][j] = max(i<k<j) {dp[i][k]+dp[k][j]+numss[i]*numss[k]*numss[j]}
        k代表区间(i, j)内剩下的最后一个气球
*/

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
        
        for(int i=0; i<=n; i++) {
            dp[i][i+1] = 0;
        }
        
        int j;
        for(int len=3; len<=n+2; len++) {
            for(int i=0; i<=n+2-len; i++) {
                j = i+len-1;
                dp[i][j] = INT_MIN;
                for(int k=i+1; k<j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+numss[i]*numss[k]*numss[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};