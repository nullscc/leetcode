/*
    dp[i]代表以i结尾(base为0)的最长上升子序列的长度
     
    当前面没有小于nums[i]的，那么 dp[i] = 1
    当前面有小于nums[i]的nums[j]，那么 dp[i] = max(dp[j] + 1)
*/

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        if(!nums.size()) return 0;
        // write your code here
        vector<int>dp(nums.size());
        dp[0] = 1;
        int ans = 1;
        for(int i=1; i<nums.size(); i++) {
            dp[i] = 1;
            
            for(int j=i-1; j>=0; j--) {
                if(nums[j]<nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};