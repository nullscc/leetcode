class Solution {
public:
    vector<string> ans;
    string output;

    void back_tracking(string &S, int start) {
        if(S.size() == start) {
            ans.emplace_back(output);
            return;
        }
        output[start] = S[start];
        back_tracking(S, start+1);
        if(!(S[start]>='0' && S[start]<='9')) {
            output[start] = S[start] ^ ' ';
            back_tracking(S, start+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        output.resize(S.size());
        back_tracking(S, 0);
        return ans;
    }
};