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
    vector<string> ans;
    vector<int> l;
    void recursion(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) {
            stringstream s;
            for(int i=0; i<l.size(); i++) {
                s<<l[i]<<"->";
            }
            s<<root->val;
            ans.emplace_back(s.str());
            return;
        }
        l.push_back(root->val);
        recursion(root->left);
        l.pop_back();

        l.push_back(root->val);
        recursion(root->right);
        l.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        recursion(root);
        return ans;
    }
};