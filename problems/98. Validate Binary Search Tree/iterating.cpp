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
    bool isValidBST(TreeNode* root) {
        long int prev = (long int)INT_MIN - 1;
        TreeNode* p = root;
        stack<TreeNode*> s;
        while(p || !s.empty()) {
            if(p) {
                s.push(p);
                p = p->left;                
            } else {
                p = s.top();
                s.pop();
                if(p->val <= prev) return false;
                prev = p->val;
                p = p->right;
            }
        }
        return true;
    }
};