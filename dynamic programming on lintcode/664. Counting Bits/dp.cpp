/*
    dp[i] = dp[i>>1] + i%2;
*/

class Solution {
public:
    /**
     * @param num: a non negative integer number
     * @return: an array represent the number of 1's in their binary
     */
    vector<int> countBits(int num) {
        // write your code here
        vector<int>dp(num+1);
        dp[0] = 0;
        for(int i=1; i<num+1; i++) {
            dp[i] = dp[i>>1] + (i&1);
        }
        return dp;
    }
};