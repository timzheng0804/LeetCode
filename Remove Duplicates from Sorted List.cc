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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* acc = head;
        while (acc) {
            ListNode* next = acc->next;
            while (next && acc->val == next->val) next = next->next;
            if (acc->next != next) {
                acc->next = next;    
            }
            acc = acc->next;
        }
        return head;
    }
};