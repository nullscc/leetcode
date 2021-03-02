class Solution {
public:
    vector<vector<int>> ans;
    vector<int>tmp;
    void dfs(TreeNode *root, int sum, int target) {
        if(!root) return;
        
        tmp.emplace_back(root->val);
        if(root->left) dfs(root->left, sum+root->val, target);
        if(root->right) dfs(root->right, sum+root->val, target);
        tmp.pop_back();

        if(!root->left && !root->right && (sum+root->val) == target) {
            ans.emplace_back(tmp);
            ans.back().emplace_back(root->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};