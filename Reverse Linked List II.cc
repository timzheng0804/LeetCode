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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head) return head;
        ListNode* reverseList = NULL;
        ListNode* pre = NULL;
        ListNode* tail = NULL;
        ListNode* acc = head;
        for (int i = 1; i < m - 1; ++i) {
            acc = acc->next;
        }
        pre = acc;
        tail = acc = m == 1 ? acc : acc->next;
        for (int i = m; i <= n; ++i) {
            ListNode* next = acc->next;
            acc->next = reverseList;
            reverseList = acc;
            acc = next;
        }
        tail->next = acc;
        if (m == 1) return reverseList;
        pre->next = reverseList;
        return head;
    }
};