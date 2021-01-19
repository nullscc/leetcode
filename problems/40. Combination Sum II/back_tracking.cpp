class Solution {
public:
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> visited;
    void back_tracking(vector<int>& candidates, int target, int sum, int start) {
        if(sum>target) return;
        if(sum==target) {
            ans.push_back(output);
            return;
        }
        for(int i=start; i<candidates.size(); i++) {
            if(i>0 && candidates[i]==candidates[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            output.push_back(candidates[i]);
            back_tracking(candidates, target, sum + candidates[i], i+1);
            output.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        visited.resize(candidates.size());
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0, 0);
        return ans;
    }
};