/*
    使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
    注意到以下性质：
        1. 左指针左边均为非零数；
        2. 右指针左边直到左指针处均为零。
    所以每次交换都是碰到右指针的第一个数和最左边的0交换
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
