/*
    此题一个很重要信息是数据无重复，且1 2 1 和 1 1 2是两种，而不是一种

    dp[i]表示有多少种方式可以组合成i
    dp[i] = sum of dp[j]，其中j满足:
        1. 是一个比i小的数(包含等于)
        2. j=i-num，num表示最后一个取的数
*/

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=0; i<=target; i++) {
            for(auto num: nums) {
                if(i >= num) dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};