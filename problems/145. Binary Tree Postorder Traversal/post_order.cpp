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
    vector<int> ans;
    void search(TreeNode *p) {
        if(!p) return;
        search(p->left);
        search(p->right);
        ans.emplace_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        search(root);
        return ans;
    }
};