class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum = sum + nums[i];
        }
        int sum2 = 0;
        int i;
        for(i=0; i<nums.size(); i++) {
            sum2 = sum2 + nums[i];
            if(sum2 > sum-sum2) break;
        }
        auto begin = nums.begin();
        return vector<int>(begin, begin+i+1);
    }
};