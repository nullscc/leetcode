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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        map<TreeNode*, TreeNode*>parent;
        TreeNode *p;
        int sum_p;
        queue<int> sum_q;
        queue<TreeNode *> q;
        sum_q.push(root->val);
        q.push(root);
        parent[root] = nullptr;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                p = q.front(); q.pop();
                sum_p = sum_q.front(); sum_q.pop();
                if(p->left) {
                    parent[p->left] = p;
                    q.push(p->left);
                    sum_q.push(sum_p+p->left->val);
                }
                if(p->right) {
                    parent[p->right] = p;
                    q.push(p->right);
                    sum_q.push(sum_p+p->right->val);
                }
                // 省去了多次拷贝
                if(!p->left && !p->right && sum_p == targetSum) {
                    vector<int> path;
                    TreeNode *tmp_p = p;
                    while(tmp_p) {
                        path.emplace_back(tmp_p->val);
                        tmp_p = parent[tmp_p];
                    }
                    reverse(path.begin(), path.end());
                    ans.emplace_back(path);
                }
            }
        }
        return ans;
    }
};