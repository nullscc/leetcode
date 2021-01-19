class Solution {
public:
    vector<vector<string>> ans;
    vector<string> output;
    vector<vector<bool>> dp;
    bool is_palindrome(int i, int j) {
        return dp[i][j];
    }

    void back_tracking(string& s, int start) {
        if(start==s.size()) {
            ans.emplace_back(output);
            return;
        }
        
        for(int i=start; i<s.size(); i++) {
            if(is_palindrome(start, i)) {
                output.emplace_back(s.substr(start, i-start+1));
                back_tracking(s, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string &s) {
        // 动态规划转移方程为: dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1])
        // dp[i][j]代表s[i..j](i, j均inclusive)是否回文字符串
        dp.resize(s.size(), vector<bool>(s.size()));
        for(int l=0; l<s.size(); l++) {
            for(int i=0; i+l<s.size(); i++) {
                int j = i+l;
                if(l==0) {
                    dp[i][j] = true;
                } else if(l==1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }
        back_tracking(s, 0);
        return ans;
    }
};