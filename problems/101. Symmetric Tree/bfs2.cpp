class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        TreeNode *p, *q;

        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()) {
            p = q1.front();
            q1.pop();
            q = q2.front();
            q2.pop();

            if(!p && !q) continue;
            if((!p || !q) || (p->val != q->val)) return false;
            q1.push(p->left);
            q1.push(p->right);

            q2.push(q->right);
            q2.push(q->left);
        }
        return true;
    }
};