class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* ans;
        queue<TreeNode*> q, q1, q2;
        TreeNode *p, *p1, *p2;
        ans = new TreeNode(root1->val+root2->val);
        q.push(ans);
        q1.push(root1);
        q2.push(root2);
        while(!q.empty()) {
            p = q.front();
            p1 = q1.front();
            p2 = q2.front();
            q.pop();
            q1.pop();
            q2.pop();
            TreeNode *tmp;
            if(p1->left && p2->left) {
                tmp = new TreeNode(p1->left->val+p2->left->val);
                p->left = tmp;
                q.push(p->left);
                q1.push(p1->left);
                q2.push(p2->left);
            } else if(!p1->left || !p2->left ) {
                if(p1->left) {
                    p->left = p1->left;
                } else if(p2->left) {
                    p->left = p2->left;
                }
            }
            
            if(p1->right && p2->right) {
                tmp = new TreeNode(p1->right->val+p2->right->val);
                p->right = tmp;
                q.push(p->right);
                q1.push(p1->right);
                q2.push(p2->right);
            } else if(!p1->right || !p2->right ) {
                if(p1->right) {
                    p->right = p1->right;
                } else if(p2->right) {
                    p->right = p2->right;
                }
            }
        }
        return ans;
    }
};