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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        TreeNode *p;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            ans.emplace_back(vector<int>());
            for(int i=0; i<sz; i++) {
                p = q.front(); q.pop();
                ans.back().emplace_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};