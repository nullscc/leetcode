class Solution {
public:
    // 和back_tracking3.cpp思想是一样的，只不过copy的不一样而已
    vector<string> letterCasePermutation(string S) {
        vector<string> result{S};
        for (int i = 0; i < S.size(); i++) {
            if (isupper(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = tolower(temp[i]);
                    result.emplace_back(move(temp));    // 这里move的作用在于避免内存的搬迁或者内存拷贝
                }
            } else if (islower(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = toupper(temp[i]);
                    result.emplace_back(move(temp));
                }
            }
        }
        return result;
    }
};