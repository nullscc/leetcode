class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                n++;
                continue;
            }
            nums[i-n] = nums[i];
        }
        int i=nums.size()-1;
        while(n>0) {
            nums[i--] = 0;
            n--;
        }
    }
};