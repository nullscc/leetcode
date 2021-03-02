/*
    可重用树
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* ans, *p, *p1, *p2;
        vector<TreeNode*> trees;
        queue<TreeNode*> q1, q2;
        trees.push_back(nullptr);
        q1.push(root1);
        q2.push(root2);
        int count = 1;
        while(!q1.empty() && !q2.empty()) {
            int len = q1.size();
            bool flag = true;
            for(int i=0; i<len; i++) {
                p1 = q1.front();
                q1.pop();
                p2 = q2.front();
                q2.pop();
                
                if(!p1 && !p2) {
                    q1.push(nullptr);
                    q2.push(nullptr);
                    q1.push(nullptr);
                    q2.push(nullptr);
                    p = nullptr;
                } else if(p1 && !p2) {
                    flag = false;
                    p = new TreeNode(p1->val);
                    q1.push(p1->left);
                    q2.push(nullptr);
                    q1.push(p1->right);
                    q2.push(nullptr);
                    
                } else if(p2 && !p1) {
                    flag = false;
                    p = new TreeNode(p2->val);
                    q1.push(nullptr);
                    q2.push(p2->left);
                    q1.push(nullptr);
                    q2.push(p2->right);
                } else {
                    flag = false;
                    p = new TreeNode(p1->val+p2->val);
                    q1.push(p1->left);
                    q2.push(p2->left);
                    q1.push(p1->right);
                    q2.push(p2->right);
                }
                trees.push_back(p);
                if(count == 1) {
                    ans = p;
                } else if(trees[count/2]){
                    if(count % 2 == 0) {
                        trees[count/2]->left = p;
                    } else {
                        trees[count/2]->right = p;
                    }
                }
                count++;
            }
            if(flag) break;
        }
        return ans;
    }
};