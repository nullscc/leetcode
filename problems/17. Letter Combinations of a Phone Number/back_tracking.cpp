class Solution {
public:
    map<char, string>map_data = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void dfs(string& digits, int deep, vector<string>& ans, string& output) {
        if(!digits.size()) return;
        if(deep==digits.size()) {
            ans.emplace_back(output);
            return;
        }

        for(int i=0; i<map_data[digits[deep]].size(); i++) {
            output[deep] = map_data[digits[deep]][i];
            dfs(digits, deep+1, ans, output);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output(digits.size(), ' ');
        
        dfs(digits, 0, ans, output);

        return ans;
    }
};