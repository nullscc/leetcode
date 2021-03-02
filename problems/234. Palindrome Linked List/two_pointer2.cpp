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
    void reverse_list(ListNode* &head) {
        ListNode *p = (ListNode *)new ListNode(0);
        
        ListNode *q = head;
        ListNode *tmp;
        while(q) {
            tmp = q->next;
            q->next = p->next;
            p->next = q;
            q = tmp;            
        }
        head = p->next;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *fast=head, *slow=head;
        vector<int> s;
        ListNode *prev;
        while(fast && fast->next) {
            s.push_back(slow->val);
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast) {
            prev = slow;
            slow = slow->next;
        }
        reverse_list(prev->next);
        ListNode *p = prev->next;
        ListNode *q = head;
        while(p) {
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        reverse_list(prev->next);
        return true;
    }
};