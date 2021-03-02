/*
    与leetcode 53思想类似，看似是区间型动态规划，实际上是序列型
    dp[i][0]代表以i结尾的最大，dp[i][1]代表以j结尾的最小
    当nums[i]>0
        dp[i][0] = max(dp[i-1][0]*nums[i], nums[i]);
        dp[i][1] = min(dp[i-1][1]*nums[i], nums[i]);
    当nums[i]<0
        dp[i][0] = max(dp[i-1][1]*nums[i], nums[i]);
        dp[i][1] = min(dp[i-1][0]*nums[i], nums[i]);
    当nums[i]==0
        dp[i][0] = dp[i][1] = 0
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        if(!nums.size()) return 0;
        
        // write your code here
        vector<vector<int>>dp(nums.size(), vector<int>(2));
        
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int ans = dp[0][0];
        for(int i=1; i<dp.size(); i++) {
            if(nums[i] > 0) {
                dp[i][0] = max(dp[i-1][0]*nums[i], nums[i]);
                dp[i][1] = min(dp[i-1][1]*nums[i], nums[i]);
            } else {
                dp[i][0] = max(dp[i-1][1]*nums[i], nums[i]);
                dp[i][1] = min(dp[i-1][0]*nums[i], nums[i]);
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};