/*
    dp[i][w]表示一直到编号为i-1的数字有多少种方式能凑出数字w
    dp[i][w] = dp[i-1][w] + dp[i-1][w-nums[i-1]]
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
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1));
        dp[0][0] = 1;       // 不用一个数字可以有多少种方式可以拼出数字0
        for(int i=1; i<=target; i++) {
            dp[0][i] = 0;
        }
        for(int i=1; i<=nums.size(); i++) {
            for(int w=0; w<=target; w++) {
                dp[i][w] = dp[i-1][w];
                if(w >= nums[i-1]) {
                    dp[i][w] += dp[i-1][w-nums[i-1]];
                }
            }
        }
        
        return dp[nums.size()][target];
    }
};