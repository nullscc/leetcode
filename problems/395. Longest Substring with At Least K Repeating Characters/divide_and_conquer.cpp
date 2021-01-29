/*
只要有字符出现的次数不足k次，就以该字符为分割点分割成较短的字符重新判定
*/

class Solution {
public:
    int recursion(string &s, int start, int end, int k) {
        if(end < start || end-start+1 < k) return 0;
        unordered_map<char, int> m;

        for(int i=start; i<=end; i++) m[s[i]]++;

        int pre_index = start, ret = 0;
        bool found = false;
        for(int i=start; i<=end; i++) {
            if(m[s[i]] < k) {
                found = true;
                ret = max(ret, recursion(s, pre_index, i-1, k));
                pre_index = i;
            }
        }
        if(!found) return end-start+1;

        if(found && pre_index==start) ret = max(ret, recursion(s, pre_index+1, end, k));
        else ret = max(ret, recursion(s, pre_index, end, k));
        return ret;
    }
    int longestSubstring(string s, int k) {
        return recursion(s, 0, s.size()-1, k);
    }
};