class Solution {
public:
    vector<vector<int>> ans;
    vector<int>output;

    void back_tracking(vector<int>& candidates, int target, int &sum, int start, int deep, int len) {
        // 这里为了保证unique，费了好大劲
        if(sum>target) return;
        if(deep>len) return;

        if(sum == target) {
            if(deep!=len) return;

            ans.push_back(output);
            return;
        }
        for(int i=start; i<candidates.size(); i++) {
            sum = sum + candidates[i];
            output.push_back(candidates[i]);
            back_tracking(candidates, target, sum, i, deep+1, len);
            output.pop_back();
            sum = sum - candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int max_len = min(target, 150);
        int sum=0;

        // 这种情况下用控制长度的方法，时耗非常多
        for(int i=1; i<=max_len; i++) {
            back_tracking(candidates, target, sum, 0, 0, i);
        }
        return ans;
    }
};