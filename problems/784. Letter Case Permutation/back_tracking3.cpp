class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans{ S };
        for (int i = 0; i < S.size(); i++)
            if (isalpha(S[i])) {
                for (int j = ans.size() - 1; j >= 0; j--) {
                    ans.emplace_back(ans[j]);
                    ans[j][i] ^= ' '; // 转换大小写
                }
            }
        return ans;
    }
};