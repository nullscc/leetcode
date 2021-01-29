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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* p = nullptr;
        int sum, tmp;
        while(l1 && l2) {
            sum = l1->val + l2->val;
            l1->val = sum;
            if(p && p->val >= 10) {
                p->val = p->val % 10;
                l1->val++;
            }
            p = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1) {
            if(p->val >= 10) {
                p->val = p->val % 10;
                l1->val++;
            }
            p = l1;
        }
        if(l2) {
            p->next = l2;
            if(p->val >= 10) {
                p->val = p->val % 10;
                p->next->val++;
            }
            p = p->next;
        }
        while(p && p->val >= 10) {
            p->val = p->val % 10;
            if(p->next) {
                p->next->val += 1;
            } else {
                p->next = new ListNode(1);
            }
            p = p->next;
        }
        
        return ans;
    }
};