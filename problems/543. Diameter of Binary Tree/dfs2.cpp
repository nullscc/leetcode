/*
    dfs返回深度
*/
class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        ans = max(ans, l+r+1);
        return max(l+1, r+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans-1;
    }
};