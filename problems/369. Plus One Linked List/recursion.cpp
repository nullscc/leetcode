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
    int recursion(ListNode* head) {
        if(!head) return 1;
        
        int extra = recursion(head->next);
        int ret = (head->val + extra) / 10;
        head->val = (head->val + extra) % 10;
        return ret;
    }

    ListNode* plusOne(ListNode* head) {
        if(!head) return nullptr;

        int extra = recursion(head);
        ListNode *ret = head;
        if(extra) {
            ret = new ListNode(extra, head);
        }
        return ret;
    }
};