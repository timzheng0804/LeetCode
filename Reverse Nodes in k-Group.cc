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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* newHead = head;
        ListNode* tail = head;
        int acc = k - 1;
        while (tail && acc) {
            tail = tail->next;
            --acc;
        }
        if (!tail) return head;
        tail->next = reverseKGroup(tail->next, k);
        tail = tail->next;
        for (int i = 0; i < k; ++i) {
            ListNode* next = newHead->next;
            newHead->next = tail;
            tail = newHead;
            newHead = next;
        }
        return tail;
    }
};