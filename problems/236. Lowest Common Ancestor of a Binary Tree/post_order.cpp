/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *first=nullptr, *second=nullptr;
        vector<TreeNode*> l1, l2;
        TreeNode *t=root;
        TreeNode *last_r=nullptr;
        while(t || l2.size()) {
            if(t) {
                if(!first) l1.emplace_back(t);
                l2.emplace_back(t);
                t = t->left;
            } else {
                t = l2[l2.size()-1];
                if(t->right && t->right != last_r) {
                    t = t->right;
                    if(!first) l1.emplace_back(t);
                    l2.emplace_back(t);
                    t = t->left;
                } else {
                    if(!first) l1.pop_back();
                    l2.pop_back();
                    if(first && !second && ((t->val==p->val || t->val==q->val))) {
                        l2.emplace_back(t);
                        second = t;
                    }
                    if(second) {
                        break;
                    }
                    if(!first && (t->val==p->val || t->val==q->val)) {
                        first = t;
                        l1.emplace_back(t);
                    }
                    last_r = t;
                    t = nullptr;
                }
            }
        }
        
        set<TreeNode*> ss;
        for(auto t: l1) {
            ss.insert(t);
        }
        for(int i=l2.size()-1; i>=0; i--) {
            if(ss.find(l2[i]) != ss.end()) return l2[i];
        }
        return nullptr;
    }
};