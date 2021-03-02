class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        // write your code here
        // 1. 先处理可以快速判断s的任意区间组成的字符是否是回文串的数组f
        vector<vector<bool>> f(s.size(), vector<bool>(s.size(), false));
        
        // 处理回文串为奇数的情况
        for(int i=0; i<s.size(); i++) {
            f[i][i] = true;
            for(int j=1; i-j>=0 && i+j<s.size(); j++) { // 以s[i]为中心字符向两边扩张，j代表扩张长度
                if(s[i-j] != s[i+j]) {
                    break;
                }
                f[i-j][i+j] = true;
            }
        }
        
        // 处理回文串为偶数的情况
        for(int i=1; i<=s.size(); i++) {
            for(int j=1; i-j>=0 && i+j-1<s.size(); j++) { // 以s[i]之前的竖线向两边扩张，j代表扩张长度
                if(s[i-j] != s[i+j-1]) {
                    break;
                }
                f[i-j][i+j-1] = true;
            }
        }
        
        vector<int>dp(s.size()+1);
        dp[0] = 0;
        // dp[i]代表以s[0]-s[i-1]最少能分割的回文串
        for(int i=1; i<dp.size(); i++) {
            dp[i] = INT_MAX;
            for(int j=0; j<=i-1; j++) {
                if(f[j][i-1])
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
        return dp[s.size()]-1;
    }
};