/*
将数组排序，尝试将数组的每个数字放到对应的子集中，如果最终能放完，就找到了

主要想不到将数组排序
*/
class Solution {
public:
    vector<int> group;
    
    bool back_tracking(vector<int>& nums, int target, int k, int index) {
        if(index == -1) return true;

        for(int i=0; i<k; i++) {
            if(group[i]+nums[index] <= target) {
                group[i] += nums[index];
                if(back_tracking(nums, target, k, index-1)) return true;
                group[i] -= nums[index];
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        int sum = 0;
        for(int i: nums) target += i;
        if(target % k != 0) return false;
        
        sort(nums.begin(), nums.end());
        
        if(nums[nums.size()-1] > target) return false;
        group.resize(k);
        target /= k;
        
        return back_tracking(nums, target, k, nums.size()-1);
    }
};