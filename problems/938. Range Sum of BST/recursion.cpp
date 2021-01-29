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
    int ans=0;
    void search(TreeNode* t, int low, int high) {
        if(!t) return;
        search(t->left, low, high);
        if(t->val>=low && t->val<=high) ans += t->val; 
        search(t->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        search(root, low, high);
        
        // 最大差不多18亿个，所以不会越界
        return ans;
    }
};