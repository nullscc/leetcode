class Solution {
public:

    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans, int len, map<int, bool>&visited, vector<int>&output) {
        if(len==0) {
            ans.push_back(output);
            return;
        }
        for(int k=start; k<nums.size(); k++) {
            if(visited.count(k) && visited[k]) continue;

            visited[k] = true;
            output.push_back(nums[k]);
            dfs(nums, k+1, ans, len-1, visited, output);
            visited[k] = false;
            output.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        map<int, bool>visited;
        ans.push_back({});
        
        for(int len=1; len<=nums.size(); len++) {
            dfs(nums, 0, ans, len, visited, output);
        }

        return ans;
    }
};