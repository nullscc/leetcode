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
    map<int, int> index;
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int i, int j, int m, int n) {
        if(i>j || m>n) return nullptr;
        TreeNode *node = new TreeNode(preorder[i]);
        int k = index[preorder[i]];
        
        node->left = build(preorder, inorder, i+1, i+k-m, m, k-1);
        node->right = build(preorder, inorder, i+k-m+1, j, k+1, n);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = preorder.size();
        for(int i=0; i<sz; i++) {
            index[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, sz-1, 0, sz-1);
    }
};