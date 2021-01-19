class Solution {
public:
    void back_tracking(vector<int>& nums, vector<vector<int>> &ans, int deep) {
        // 维护动态数组法
        int len = nums.size();
        if(deep==len) {
            ans.emplace_back(nums);
            return;
        }
        for(int i=deep; i<len; i++) {
            if(i!=deep) swap(nums[i], nums[deep]);
            back_tracking(nums, ans, deep+1);
            if(i!=deep) swap(nums[i], nums[deep]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();

        vector<vector<int>> ans;

        back_tracking(nums, ans, 0);
        
        return ans;
    }
};