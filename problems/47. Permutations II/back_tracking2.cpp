class Solution {
public:
    // 此题难点在于怎么去重
    // 去重的关键在于每一层的起始点不能有想同的数字
    vector<vector<int>> ans;
    vector<int> output;
    vector<bool>visited;  // visited用来控制哪个index已经访问过了，用vector来存储可以减少点时耗，如果用map还要用count函数来判断是否存在
    void back_tracking(vector<int>& nums, int len) {
        if(len==0) {
            ans.emplace_back(output);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            /* 
                这里
                    i>0 && nums[i] == nums[i - 1] && !visited[i - 1])
                保证的逻辑在于如果前项没选入(实际上是检测的上层调用是否选入)，这项与前项又相等了，那么这项再选必然会在这一层重复选入
                如果前项选入了，那么说明前项被上层选入了，那么这层自然可以选
            */
            if(visited[i] || (i>0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;
            visited[i] = true;
            output.emplace_back(nums[i]);
            back_tracking(nums, len-1);
            output.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());         // 默认会初始化成false
        sort(nums.begin(), nums.end());
        back_tracking(nums, nums.size());
        return ans;
    }
};