// 记忆化搜索

class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    vector<vector<int>> f;
    void compute(string &s, int i, int j) {
        if(f[i][j] != -1) {
            return;
        }
        
        if(i == j) {
            f[i][j] = 1;
            return;
        }
        if(j == i+1) {
            if(s[i] == s[j]) {
                f[i][j] = 2;
            } else {
                f[i][j] = 1;
            }
            
            return;
        }
        compute(s, i+1, j);
        compute(s, i, j-1);
        compute(s, i+1, j-1);
        f[i][j] = max(f[i+1][j], f[i][j-1]);
        if(s[i] == s[j]) {
            f[i][j] = max(f[i][j], f[i+1][j-1]+2);
        }
    }
     
    int longestPalindromeSubseq(string &s) {
        // write your code here
        int n = s.size();
        if(n == 0) return 0;

        if(n == 1) return 1;
        f.resize(n, vector<int>(n, -1));
        compute(s, 0, n-1);
        return f[0][n-1];
    }
};