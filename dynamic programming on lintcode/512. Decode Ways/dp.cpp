/*
    这个是错的，因为分支情况分的太多导致没法推导了，这种情况算是建模不合适
*/

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    bool can(string &s, int i) {
        // 判断i和它前面一个数字是否能组成一个字母
        // i必须大于0
        int m = s[i-1]-'0';
        if(m == 0) return false;
        
        if(m > 2) return false;
        
        int n = s[i]-'0';
        if(m == 2 && n>6) return false;
    
        return true;
    }
    int numDecodings(string &s) {
        if(!s.size()) return 0;
        
        // write your code here
        vector<int>dp(s.size()+1);
        
        dp[0] = 1;
        if(s[0]-'0' == 0) dp[1] = 0;
        else dp[1] = 1;
        
        for(int i=2; i<dp.size(); i++) {
            if(s[i-1]-'0' == 0 && s[i-2]-'0' == 0) {    // 如果连续的两个0，必不能组成
                return 0;
            }
            
            if(s[i-1]-'0' == 0) {   // 如果当前是0，那么只能和前面一个一起组成
                dp[i] = dp[i-1];
                continue;
            }
            
            if(!can(s, i-1)) {
                // if(s[i-2]-'0' == 0) return 0;   // 这句语句是错的，如果前面那个是0，有可能可以，有可能不可以，比如:
                                                    // "11111878787676172120121101212918291829819" 与 "2789011203"
                dp[i] = dp[i-1];
            } else {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[s.size()];
    }
};