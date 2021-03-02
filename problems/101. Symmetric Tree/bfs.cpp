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
    bool is_palindromic(vector<int> &tmp) {
        int len = tmp.size();
        int i= len/2 -1, j = len/2;
        while(i>=0) {
            if(tmp[i--] != tmp[j++]) return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while(!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            for(int i=0; i<len; i++) {
                cur = q.front();
                if(cur) {
                    tmp.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else {
                    tmp.push_back(101);
                }
                q.pop();
            }
            if(!is_palindromic(tmp)) return false;
        }
        return true;
    }
};