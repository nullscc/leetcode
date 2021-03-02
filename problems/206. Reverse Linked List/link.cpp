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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode();;
        ListNode *p = head;
        while(p) {
            ListNode *tmp = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = tmp;
        }
        return dummy->next;
    }
};