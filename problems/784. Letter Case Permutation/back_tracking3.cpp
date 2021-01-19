class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans{ S };
        for (int i = 0; i < S.size(); i++)
            if (isalpha(S[i])) {
                /* 每次碰到字母，数量必翻倍，翻倍的来源是之前已经组合好的序列分别和大小写组合
                    即每次碰到新字母，都将以新碰到的的字母为终点，将0~终点分为两部分：一部分为终点字母，另一部分是之前已经组合好的字符串序列，
                    新碰到的字母与已经组合好的序列组合的可能性只有两种，以s(已经组合好的字符串)和''(新碰到的单个字符，这里假设为): 
                        1. s 与 'a'
                        2. s 与 'A'
                */
                for (int j = ans.size() - 1; j >= 0; j--) {
                    ans.emplace_back(ans[j]);
                    ans[j][i] ^= ' '; // 转换大小写
                }
            }
        return ans;
    }
};