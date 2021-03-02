/*
    dp[i]代表如果某个玩家面对i个石子，是必败(false)还是必胜(true)
    dp[i] = !dp[i-1] || !dp[i-2]; 必胜的情况必然是拿走一个石子或者两个石子必然能让面对更少石子的玩家必败(因为题意已经假设玩家是最聪明的)
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<int> dp(n+1);
        dp[0] = false;
        dp[1] = true;
        for(int i=2; i<=n; i++) {
            dp[i] = !dp[i-1] || !dp[i-2];
        }
        return dp[n];
    }
};