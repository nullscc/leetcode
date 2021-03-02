/*
    书本编号为0~n-1
    dp[i][m]代表m个人抄写到编号为i-1的书本所耗费的最短时间
*/
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        vector<vector<int>> dp(pages.size()+1, vector<int>(k+1));
        for(int i=0; i<dp.size(); i++) {
            for(int m=0; m<=k; m++) {
                if(!i) {
                    dp[i][m] = 0;
                    continue;
                }
                if(!m) {
                    dp[i][m] = INT_MAX;
                    continue;
                }
                
                dp[i][m] = INT_MAX;
                int sum = 0;
                for(int j=i-1; j>=0; j--) {
                    sum += pages[j];
                    dp[i][m] = min(dp[i][m], max(dp[j][m-1], sum));
                }
                
            }
        }
        return dp[pages.size()][k];
    }
};