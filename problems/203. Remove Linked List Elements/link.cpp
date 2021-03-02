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
 // 用哨兵(创建一个伪头节点)代码上看起来会简洁一点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans = head;
        ListNode *p = ans;
        ListNode *need_del;
        while(p && p->val == val) {
            need_del = p;
            ans = p->next;
            p = p->next;
            delete need_del;
        }
        while(p) {
            if(p->next && p->next->val == val) {
                need_del = p->next;
                p->next = p->next->next;
                delete need_del;
            } else {
                p = p->next;
            }
        }
        return ans;
    }
};