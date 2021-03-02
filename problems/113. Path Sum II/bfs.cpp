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
        TreeNode *p;
        int sum_p;
        vector<int> sum_item_p;
        queue<int> sum_q;
        queue<vector<int>> sum_item_q;
        queue<TreeNode *> q;
        sum_q.push(root->val);
        sum_item_q.push({root->val});
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                p = q.front(); q.pop();
                sum_p = sum_q.front(); sum_q.pop();
                sum_item_p = sum_item_q.front(); sum_item_q.pop();
                if(p->left) {
                    vector<int> tmp = sum_item_p;       // 这里复制太耗时间了
                    q.push(p->left);
                    sum_q.push(sum_p+p->left->val);
                    tmp.push_back(p->left->val);
                    sum_item_q.push(tmp);
                }
                if(p->right) {
                    vector<int> tmp = sum_item_p;
                    q.push(p->right);
                    sum_q.push(sum_p+p->right->val);
                    tmp.push_back(p->right->val);
                    sum_item_q.push(tmp);
                }
                if(!p->left && !p->right && sum_p == targetSum) {
                    ans.push_back(sum_item_p);
                }
            }
        }
        
        return ans;
    }
};