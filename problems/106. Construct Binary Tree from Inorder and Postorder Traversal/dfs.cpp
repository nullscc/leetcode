class Solution {
public:
    map<int, int> index;

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int i, int j, int m, int n) {
        if(i>j) return nullptr;
        TreeNode *p = new TreeNode(postorder[n]);
        int k = index[postorder[n]];
        p->left = dfs(inorder, postorder, i, k-1, m, m+k-1-i);
        p->right = dfs(inorder, postorder, k+1, j, n-j+k, n-1);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};