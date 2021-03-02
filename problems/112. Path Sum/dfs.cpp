class Solution {
public:
    bool dfs(TreeNode* p, int sum, int target) {
        if(!p) {
            return false;
        }
        int cur = sum + p->val;
        if(!p->left && !p->right && cur == target) return true;
        if(dfs(p->left, cur, target)) return true;
        if(dfs(p->right, cur, target)) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};