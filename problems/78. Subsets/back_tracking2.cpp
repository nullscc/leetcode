class Solution {
public:

    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans, int len, int deep) {
        if(len==0) {
            vector<int> tmp;
            for(int i=0; i<deep; i++) {
                tmp.push_back(nums[i]);
            }
            ans.push_back(tmp);
            return;
        }
        for(int k=start; k<nums.size(); k++) {
            swap(nums[deep], nums[k]);
            dfs(nums, k+1, ans, len-1, deep+1);
            swap(nums[deep], nums[k]);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        map<int, bool>visited;
        ans.push_back({});
        
        for(int len=1; len<=nums.size(); len++) {
            dfs(nums, 0, ans, len, 0);
        }

        return ans;
    }
};