class Solution {
public:
    void back_tracking(vector<int>& nums, map<int,bool>&visit, vector<vector<int>> &ans, int deep, vector<int>&output) {
        // 标记法，优点是按照字典序排列，缺点是需要额外维护一个visit字典数据
        int len = nums.size();
        if(deep==len) {
            ans.push_back(output);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!visit[nums[i]]) {
                visit[nums[i]] = true;
                output[deep] = nums[i];
                back_tracking(nums, visit, ans, deep+1, output);
                visit[nums[i]] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();

        vector<vector<int>> ans;
        map<int, bool> visit;
        for(int i=0; i<nums.size(); i++) {
            visit[i] = false;
        }

        vector<int>output(len);
        back_tracking(nums, visit, ans, 0, output);
        
        return ans;
    }
};