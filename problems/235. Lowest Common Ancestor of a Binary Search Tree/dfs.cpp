/*
    dfs返回是否找到
    依据每一个二叉排序树节点都和一个区间关联原理
*/

class Solution {
public:
    TreeNode* ans;    // 题意说答案一定存在
    int m1, m2;       // m1 m2指的是每个区间关联的最大值
    void dfs(TreeNode *p, int p1, int p2, int depth) {
        if(!p) return;
        if(p1 <= m1 && p2 >= m2) {
            if(p->val>=m1 && p->val<=m2) {
                ans = p;    // 因为是dfs，所以最后的满足条件的ans一定是最下层的
            }
        } else {
            return;
        }
        if(p->left && p->val>m2) dfs(p->left, p1, p->val, depth+1);     // 这里p->val>m2至关重要，不能斜p->val>=m2
        if(p->right && p->val<m1) dfs(p->right, p->val, p2, depth+1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m1 = min(p->val, q->val);
        m2 = max(p->val, q->val);
        dfs(root, INT_MIN, INT_MAX, 1);
        return ans;
    }
};