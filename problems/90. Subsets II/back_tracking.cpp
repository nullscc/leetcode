class Solution {
public:
    vector<vector<int>> ans;
    vector<int> output;
    vector<bool> visited;

    void back_tracking(vector<int>& nums, int start, int len) {
        if(len==0) {
            ans.emplace_back(output);
            return;
        }
        
        for(int i=start; i<nums.size(); i++) {
            if(i>0 && nums[i-1]==nums[i] && !visited[i-1]) continue;
            visited[i] = true;
            output.emplace_back(nums[i]);
            back_tracking(nums, i+1, len-1);
            visited[i] = false;
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        if(!len) return ans;
        visited.resize(nums.size());
        ans.push_back(output);
        sort(nums.begin(), nums.end());
        for(int len=1; len<=nums.size(); len++) {
            back_tracking(nums, 0, len);
        }
        
        return ans;
    }
};