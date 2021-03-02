/*
    dp[i]代表以i结尾(base为0)最长连续升序子序列的个数

    从左到右为例
    当后者比前者大 dp[i] = dp[i-1] + 1
    当前者比后者大或相等 dp[i] = 1
*/
class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int check(vector<int> &A, int l2r) {
        int ans = 1;
        if(!A.size()) return 0;
        vector<int>dp(A.size());
        // l2r为1时代表从左向右，为-1时代表从右向左
        int i;
        if(l2r == 1) {
            i = 1;
            dp[0] = 1;
        }
        else {
            i = A.size()-2;
            dp[A.size()-1] = 1;
        }
        
        while(i>=0 && i<A.size()) {
            if(l2r == 1 && A[i]>A[i-1]) {
                dp[i] = dp[i-1]+1;
            } else if(l2r == -1 && A[i]>A[i+1]) {
                dp[i] = dp[i+1]+1;
            } else {
                dp[i] = 1;
            }
            ans = max(ans, dp[i]);
            i += l2r;
        }
        return ans;
    }
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here
        return max(check(A, 1), check(A, -1));
    }
};