/*
    这个的转移方程比较难搞

    dp[i]代表到index 为i-1时有多少种解码方式
    当相邻的两个可以连起来组成一个字母时
        dp[i] = dp[i-1] + dp[i-2]
    当相邻的两个不能连起来组成一个字母时
        dp[i] = dp[i-1]
*/

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        if(!s.size()) return 0;
        
        // write your code here
        vector<int>dp(s.size()+1);
        
        dp[0] = 1;
        
        for(int i=1; i<dp.size(); i++) {
            dp[i] = 0;
            if(s[i-1] >= '1' && s[i-1] <= '9') {
                dp[i] += dp[i-1];
            }

            if(i > 1) {
                int j = 10 * (s[i-2]-'0') + (s[i-1]-'0');
                if(j >= 10 && j <= 26) {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[s.size()];
    }
        
};