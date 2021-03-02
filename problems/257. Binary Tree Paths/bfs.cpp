class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        queue<string> path_q;
        TreeNode* p;
        string path_p;
        q.push(root);
        path_q.push(to_string(root->val));
        while(!q.empty()) {
            p = q.front();
            q.pop();
            path_p = path_q.front();
            path_q.pop();
            if(p->left) {
                q.push(p->left);
                path_q.push(path_p+"->"+to_string(p->left->val));
            }

            if(p->right) {
                q.push(p->right);
                path_q.push(path_p+"->"+to_string(p->right->val));
            }
            if(!p->left && !p->right) {
                ans.push_back(path_p);
            }
        }
        return ans;
    }
};