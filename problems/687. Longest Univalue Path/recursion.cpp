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
    int ans = 0;
    int recursion(TreeNode* root) {
        if(!root) return 0;

        int l_len = recursion(root->left);
        int r_len = recursion(root->right);
        if(root->right && root->right->val == root->val) {
            r_len++;
        } else {
            ans = max(ans, r_len);
            r_len = 0;
        }
        if(root->left && root->left->val == root->val) {
            l_len++;
        } else {
            ans = max(ans, l_len);
            l_len = 0;
        }

        if(root->left && root->right && root->left->val == root->right->val && root->left->val == root->val) {
            ans = max(ans, l_len + r_len);
        }

        return max(l_len, r_len);
    }
    int longestUnivaluePath(TreeNode* root) {
        int len = recursion(root);

        return max(ans, len);
    }
};