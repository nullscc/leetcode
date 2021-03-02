class Solution {
    ListNode* front;
public:
    bool recursion(ListNode* rear) {
        if (rear != nullptr) {
            if (!recursion(rear->next)) {
                return false;
            }
            if (front->val != rear->val) {
                return false;
            }
            front = front->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        front = head;
        return recursion(head);
    }
};