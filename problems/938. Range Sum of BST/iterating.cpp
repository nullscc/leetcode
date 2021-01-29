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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        stack<TreeNode*>s;
        TreeNode* p = root;
        while(p || !s.empty()) {
            if(p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                if(p->val>=low && p->val<=high) ans += p->val;
                p = p->right;
            }
        }
        
        // 最大差不多18亿，所以不会越界
        return ans;
    }
};