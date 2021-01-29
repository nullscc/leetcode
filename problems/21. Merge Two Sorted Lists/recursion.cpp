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
    ListNode* mergeTwoLists(ListNode* &l1, ListNode* &l2) {
        ListNode* ret;
        if(!l1) {
            l1 = l2;
            return 
        } 
        if(l1->val < l2->val) {
            ret = mergeTwoLists(l1->next, l2);
        } else {
            ret = mergeTwoLists(l1, l2->next);
        }
        return ret;
    }
};