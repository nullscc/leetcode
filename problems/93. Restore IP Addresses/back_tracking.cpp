class Solution {
public:
    void form(string &s, vector<string>&ans, vector<string>output, int deep, int start) {
        if((s.size() - start) < (4-deep)) return;
        if(deep == 4 && start != s.size())  return;
        
        if(deep == 4) {
            ans.emplace_back(output[0]+"."+output[1]+"."+output[2]+"."+output[3]);
            return;
        }

        string cur;
        for(int i=start; i<=s.size()-1 && i<start+3; i++) {
            if(i>start && s[start]=='0') break;
            cur = s.substr(start, i-start+1);
            if(stoi(cur)>255) break;
            output[deep] = cur;
            form(s, ans, output, deep+1, i+1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> output(4);

        form(s, ans, output, 0, 0);
        return ans;
    }
};