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
    int height(TreeNode* t) {
        if(!t) return 0;

        int hl = height(t->left);
        if(hl < 0) return hl;

        int hr = height(t->right);
        if(hr < 0) return hr;

        if(abs(hl-hr)>1) return -1;
        return max(hl, hr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(height(root)<0) return false;

        return true;   
    }
};