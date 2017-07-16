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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        while (head) {
            if (head->next) {
                pre->next = head->next;
                pre = pre->next;
                head->next = head->next->next;
            }
            pre->next = head;
            head = head->next;
            pre = pre->next;
        }
        return dummy.next;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* second = head->next;
        ListNode* third = second->next;
        
        second->next = head;
        head->next = swapPairs(third);
        return second;
    }
};