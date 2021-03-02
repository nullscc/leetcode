class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        TreeNode *p;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                p = q.front(); q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                if(i==(sz-1)) ans.emplace_back(p->val);
            }
        }
        return ans;
    }
};