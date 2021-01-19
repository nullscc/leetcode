class Solution {
public:
    vector<vector<int>>ans;
    vector<int>output;
    void back_tracking(int k, int n, int sum, int start) {
        if(sum>n || k<0) return;
        if(sum == n) {
            if(k != 0) return;
            ans.push_back(output);
            return;
        }
        for(int i=start; i<=9; i++) {
            output.push_back(i);
            back_tracking(k-1, n, sum+i, i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        back_tracking(k, n, 0, 1);
        return ans;
    }
};