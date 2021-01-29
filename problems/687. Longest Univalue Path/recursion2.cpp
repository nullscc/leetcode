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
 // 这个和recursion.cpp思想是一样的，只是代码更简洁
class Solution {
public:
    int ans = 0;
    int recursion(TreeNode* root) {
        if(!root) return 0;

        int l_len = recursion(root->left);
        int r_len = recursion(root->right);
        int left=0, right=0;
        if(root->right && root->right->val == root->val) right += r_len+1;
        if(root->left && root->left->val == root->val) left += l_len+1;

        ans = max(ans, left+right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        recursion(root);

        return ans;
    }
};