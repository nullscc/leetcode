class Solution {
public:
    /*
    这题很容易被题意中的:  unlimited number of times、less than 150 combinations给迷惑了
    不过distinct的信息很有用
    */
    vector<vector<int>> ans;
    vector<int>output;

    void back_tracking(vector<int>& candidates, int target, int &sum, int start) {
        // 通过控制start不减的方法，保证了unique

        if(sum>target) return;

        if(sum == target) {
            ans.push_back(output);
            return;
        }
        for(int i=start; i<candidates.size(); i++) {
            sum = sum + candidates[i];
            output.push_back(candidates[i]);
            back_tracking(candidates, target, sum, i);
            output.pop_back();
            sum = sum - candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        back_tracking(candidates, target, sum, 0);
        return ans;
    }
};