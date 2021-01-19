class Solution {
public:
    void parenthese(int p, int q, int n, vector<string> &ans, string &output) {
        if(q>p) return;
        if(p+q >= 2*n) {
            ans.emplace_back(output);
            return;
        }

        if(p>=n) {
            output[p+q] = ')';
            parenthese(p, q+1, n, ans, output);
        } else {
            output[p+q] = '(';
            parenthese(p+1, q, n, ans, output);

            output[p+q] = ')';
            parenthese(p, q+1, n, ans, output);
        }
    }
    vector<string> generateParenthesis(int n) {
        int p=0, q=0;
        string output(2*n, '(');
        vector<string> ans;
        parenthese(p+1, q, n, ans, output);
        return ans;
    }
};