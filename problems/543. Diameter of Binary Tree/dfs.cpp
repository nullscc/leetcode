/*
    dfs返回左右子树最长节点数
*/
class Solution {
public:
    int ans = INT_MIN;
    pair<int, int> dfs(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        auto p_l = dfs(root->left);
        auto p_r = dfs(root->right);

        int l_max = max(p_l.first, p_l.second);
        int r_max = max(p_r.first, p_r.second);
        ans = max(ans, l_max+r_max+1);
        return {l_max+1, r_max+1};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans-1;
    }
};