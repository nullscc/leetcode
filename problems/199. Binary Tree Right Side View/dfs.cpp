class Solution {
public:
    vector<int> ans;
    int has_solved_depth = 1;
    void dfs(TreeNode *root, int depth) {
        if(!root) return;
        if(has_solved_depth<depth) {
            has_solved_depth++;
            ans.emplace_back(root->val);
        }
        if(root->right) dfs(root->right, depth+1);
        if(root->left) dfs(root->left, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        ans.emplace_back(root->val);
        dfs(root, 1);
        return ans;
    }
};