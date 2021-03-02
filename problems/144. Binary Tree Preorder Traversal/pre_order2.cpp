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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *>s;
        TreeNode *p = root;
        while(p || !s.empty()) {
            if(p) {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            } else {
                p = s.top(); s.pop();
                p = p->right;
            }
        }
        
        return ans;
    }
};