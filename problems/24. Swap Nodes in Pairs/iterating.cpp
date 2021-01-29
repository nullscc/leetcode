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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* p = head;
        ListNode* prev = dummy;
        ListNode* tmp;

        while(p && p->next) {
            tmp = p->next;
            p->next = p->next->next;
            tmp->next = p;
            prev->next = tmp;
            prev = p;
            p = p->next;
        }

        prev->next = p;
        
        return dummy->next;
    }
};