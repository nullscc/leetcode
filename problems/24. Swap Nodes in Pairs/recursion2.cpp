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
    ListNode* recursion(ListNode* t) {
        // 直接交换节点
        if(!t) return nullptr;
        if(!t->next) return t;

        ListNode* p = t->next;
        t->next = p->next;
        p->next = t;
        t->next = recursion(t->next);
        return p;
    }

    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
    }
};