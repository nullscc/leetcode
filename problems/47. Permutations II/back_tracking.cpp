class Solution {
public:
    // 此题难点在于怎么去重
    vector<vector<int>> ans;
    vector<int> output;
    vector<bool>visited;  // visited用来控制哪个index已经访问过了，用vector来存储可以减少点时耗，如果用map还要用count函数来判断是否存在
    vector<set<int>> start; // 这个方案用start来控制在某一层哪个数据已经用过了，空间复杂度较高
    void back_tracking(vector<int>& nums, int len) {
        if(len==0) {
            ans.emplace_back(output);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(!visited[i] && start[len-1].find(nums[i])==start[len-1].end()) {
                start[len-1].insert(nums[i]);
                visited[i] = true;
                output.emplace_back(nums[i]);
                back_tracking(nums, len-1);
                output.pop_back();
                visited[i] = false;
            }
        }
        start[len-1].clear();
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        start.resize(nums.size()); // start用来控制在某一层哪个数据已经用过了
        visited.resize(nums.size());         // 默认会初始化成false
        back_tracking(nums, nums.size());
        return ans;
    }
};