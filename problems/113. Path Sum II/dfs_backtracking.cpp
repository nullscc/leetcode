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
    vector<vector<int>> ans;
    vector<int>tmp;
    void dfs(TreeNode *root, int sum, int target) {
        if(!root) return;
        
        if(root->left) {
            tmp.emplace_back(root->val);
            dfs(root->left, sum+root->val, target);
            tmp.pop_back();
        }
        if(root->right) {
            tmp.emplace_back(root->val);
            dfs(root->right, sum+root->val, target);
            tmp.pop_back();
        }
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