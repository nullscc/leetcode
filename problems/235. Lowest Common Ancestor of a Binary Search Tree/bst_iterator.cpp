class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int m1 = min(p->val, q->val);
        int m2 = max(p->val, q->val);
        TreeNode *ans = root;
        while(true) {
            if(m2 < ans->val) {
                ans = ans->left;
            } else if(m1 > ans->val) {
                ans = ans->right;
            } else {
                break;
            }
        }
        return ans;
    }
};