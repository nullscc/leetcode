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
    long int prev = (long int)INT_MIN - 1;
    bool recursion(TreeNode* t) {
        if(!t) return true;
        
        if(!recursion(t->left)) return false;

        if(t->val <= prev) return false;  // 这里prev定义成long int避免每次都要多一个判断
        prev = t->val;

        if(!recursion(t->right)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return recursion(root);
    }
};