class Solution {
public:
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> freq;
    void back_tracking(vector<int>& candidates, int target, int sum, int start) {
        if(sum>target) return;
        if(sum==target) {
            ans.push_back(output);
            return;
        }
        for(int i=start; i<candidates.size(); i=i+freq[i]) {
            output.push_back(candidates[i]);
            back_tracking(candidates, target, sum+candidates[i], i+1);
            output.pop_back();
        }
    }
    void get_freq(vector<int>& candidates) {
        map<int, int>tmp;
        for(int i=0; i<candidates.size(); i++) {
            tmp[candidates[i]] = 0?!tmp.count(candidates[i]):tmp[candidates[i]]+1;
        }
        for(int i=0; i<candidates.size(); i++) {
            freq.push_back(tmp[candidates[i]]--);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        get_freq(candidates);
        back_tracking(candidates, target, 0, 0);
        return ans;
    }
};