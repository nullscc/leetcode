class Solution {
public:
    vector<int> ans;
    string output;
    void back_tracking(int len, string &output, int deep, int k) {
        if(len==0) {
            ans.emplace_back(stoi(output));
            return;
        }
        
        // 加k
        char plusk = output[deep] + k;
        if(plusk<='9') {
            output[deep+1] = plusk;
            back_tracking(len-1, output, deep+1, k);
        }

        // 减k
        if(k==0) return;
        char minusk = output[deep] - k;
        if(minusk>='0') {
            output[deep+1] = minusk;
            back_tracking(len-1, output, deep+1, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        output.resize(n);
        for(int i=1; i<10; i++) {
            output[0] = '0' + i;
            back_tracking(n-1, output, 0, k);
        }
        return ans;
    }
};