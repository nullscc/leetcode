/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0, len2=0;
        ListNode *p=headA, *q=headB;
        while(p || q) {
            if(p) {
                p = p->next;
                len1++;
            }
            if(q) {
                q = q->next;
                len2++;
            }
        }
        p=headA, q=headB;
        if(len1 > len2) {
            for(int i=0; i<len1-len2; i++) {
                p = p->next;
            }
        } else {
            for(int i=0; i<len2-len1; i++) {
                q = q->next;
            }
        }
        while(p) {
            if(p == q) break;
            p = p->next;
            q = q->next;
        }
        return p;
    }
};