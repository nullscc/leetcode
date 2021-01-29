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
    ListNode* add(ListNode* l1, ListNode* l2, int extra) {
        if(!l1 && !l2 && !extra) return nullptr;

        ListNode* p = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra);
        p->next = add(l1 ? l1->next:nullptr, l2 ? l2->next:nullptr, p->val / 10);
        p->val = p->val % 10;
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};