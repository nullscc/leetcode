/*
    空间压缩版本
*/

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=1; i<=target; i++) {
            dp[i] = 0;
        }
        for(int i=1; i<=nums.size(); i++) {
            for(int w=target; w>=0; w--) {
                if(w >= nums[i-1]) {
                    dp[w] += dp[w-nums[i-1]];
                }
            }
        }
        return dp[target];
    }
};