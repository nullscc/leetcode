class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        queue<TreeNode*> q;
        queue<int> sum_q;
        TreeNode *p;
        q.push(root);
        sum_q.push(0);
        int sum;
        while(!q.empty()) {
            p = q.front(); q.pop();
            sum = sum_q.front(); sum_q.pop();
            
            int cur = sum + p->val;
            if(!p->left && !p->right && cur == targetSum) return true;

            if(p->left) {
                q.push(p->left);
                sum_q.push(cur);
            }
            if(p->right) {
                q.push(p->right);
                sum_q.push(cur);
            }
        }
        return false;
    }
};