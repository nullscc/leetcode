/*
    完全新建树
*/
class Solution {
public:
    TreeNode* ans;
    void dfs(TreeNode* root1, TreeNode* root2, TreeNode *&ans_root) {
        if(!root1 && !root2) return;
        int val = root1?root1->val:0;
        val += root2?root2->val:0;
        ans_root = new TreeNode(val);
        
        TreeNode* t1 = root1?root1->left:root1;
        TreeNode* t2 = root2?root2->left:root2;
        dfs(t1, t2, ans_root->left);

        t1 = root1?root1->right:root1;
        t2 = root2?root2->right:root2;
        dfs(t1, t2, ans_root->right);
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        dfs(root1, root2, ans);
        return ans;
    }
};