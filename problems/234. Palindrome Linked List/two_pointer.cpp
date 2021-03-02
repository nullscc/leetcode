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
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head, *slow=head;
        vector<int> s;
        while(fast && fast->next) {
            s.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast) {
            slow = slow->next;
        }
        int n = s.size()-1;
        
        while(n >= 0) {
            if(s[n--] != slow->val) return false;
            slow = slow->next;
        }
        return true;
    }
};