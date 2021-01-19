class Solution {
public:
    vector<int> codes; // 每个整数都代表一个字符串，用0~25的二进制中的0或者1来代表'a'+0~'a'+25()是否出现在这个字符串中
    int ans=0;
    void back_tracking(vector<string>& arr, int cur, int start, int len) {
        if(start == arr.size()) {
            ans = max(len, ans);
            return;
        }
        // 选
        if(codes[start] != -1 && (cur&codes[start]) == 0)
            back_tracking(arr, cur | codes[start], start+1, len+arr[start].size());

        // 不选
        back_tracking(arr, cur, start+1, len);
    }
    int maxLength(vector<string>& arr) {
        for(int i=0; i<arr.size(); i++) {
            int code = 0;
            for(int j=0; j<arr[i].size(); j++) {
                int tmp = 1<<(arr[i][j]-'a');
                // 本身重复绝对不选
                if((code&tmp) != 0) {
                    code = -1;
                    break;
                }
                code |= tmp;
            }
            codes.push_back(code);
        }

        back_tracking(arr, 0, 0, 0);
        return ans;
    }
};