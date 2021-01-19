class Solution {
public:
    vector<vector<int>> ans;
    vector<int> output;
    
    void dfs(int n, int k, int deep, int start) {
        if(n-start+1 < k-deep) return;
        if(k==deep) {
            ans.push_back(output);
            return;
        }

        for(int i=start; i<=n; i++) {
                output.push_back(i);
                dfs(n, k, deep+1, i+1);
                output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 0, 1);
        return ans;
    }
};