class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j=1;
        for(int i=0; i<nums.size(); i=i+2) {
            if((nums[i]&1) == 0) continue;
            while((nums[j]&1) == 1) {
                j = j+2;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};