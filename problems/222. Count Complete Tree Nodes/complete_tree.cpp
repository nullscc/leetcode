/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        int level = 0;
        TreeNode *p = root->left;
        while(p) {
            level++;
            p = p->left;
        }
        if(level == 0) return 1;
        int low = 1<<level;
        int high = (1<<(level+1)) - 1;
        ans = low;
        while(low < high) {             // 这里与找数的二分法不一样
            int mid = (low+high)/2;
            if(exist(root, level, mid)) {
                low = mid+1;
                ans = mid;
            } else {
                high = mid-1;
            }
        }
        if(exist(root, level, ans+1)) ans++;
        return ans;
    }

    bool exist(TreeNode* root, int level, int k) {
        int bits = 1<<(level-1);    // 二进制形式必然只有一个1，其余全是0
        while(bits) {
            if(bits & k) {          // 判断第几位
                root = root->right;
            } else {
                root = root->left;
            }
            bits = bits >> 1;
        }
        return root;
    }
};