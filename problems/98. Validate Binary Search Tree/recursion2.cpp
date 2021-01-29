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
    bool recursion(TreeNode* t, long int low, long int high) {
        if(!t) return true;
        
        if (t->val <= low || t->val >= high) return false;

        return recursion(t->left, low, t->val) && recursion(t->right, t->val, high);
    }

    bool isValidBST(TreeNode* root) {
        long int low = (long int)INT_MIN - 1, high = (long int)INT_MAX + 1;
        return recursion(root, low, high);
    }
};