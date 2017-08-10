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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* removed = &dummy;
        while (head) {
            if (head->val != val) {
                removed->next = head;
                removed = removed->next;
            }
            head = head->next;
        }
        removed->next = NULL;
        return dummy.next;
    }
};