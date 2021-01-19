class Solution {
public:
    vector<vector<string>> ans;
    vector<string> output;
    string get_palindrome(string &s, int i, int j) {
        string ret(j-i+1, ' ');
        int start = i;
        int last = j-i;
        while(j>=i) {
            ret[i-start] = ret[last--] = s[i];
            if(s[i++]!=s[j--]) return "";
        }
        return ret;
    }

    void back_tracking(string& s, int start) {
        if(start==s.size()) {
            ans.emplace_back(output);
            return;
        }
        
        for(int i=start; i<s.size(); i++) {
            string palindrome = get_palindrome(s, start, i);
            if(palindrome.size()) {
                output.emplace_back(palindrome);
                back_tracking(s, i+1);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        back_tracking(s, 0);
        return ans;
    }
};