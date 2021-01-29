/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 只换值域
    void swap(ListNode* &p, ListNode* &q) {
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }

    void recursion(ListNode* &t) {
        if(!t || !t->next) return;
        
        swap(t, t->next);
        recursion(t->next->next);
    }

    ListNode* swapPairs(ListNode* head) {
        recursion(head);
        return head;
    }
};