class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<int> cnt(26, 0);
        for(int i=0; i<s.size(); i++) {
            cnt[s[i]-'a']++;
        }
        while(ans.size() < s.size()) {
            for(int i=0; i<26; i++) {
                if(cnt[i] > 0) {
                    ans += i+'a';
                    cnt[i]--;
                }
            }
            if(ans.size() >= s.size()) break;
            for(int i=25; i>=0; i--) {
                if(cnt[i] > 0) {
                    ans += i+'a';
                    cnt[i]--;
                }
            }
        }
        return ans;
    }
};