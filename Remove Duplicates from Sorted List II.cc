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
        ListNode dummy(0);
        ListNode* noDupList = &dummy;
        int count = 0;
        while (head) {
            count = 0;
            while (head->next && head->val == head->next->val) {
                ++count;
                head = head->next;
            }
            if (!count) {
                noDupList->next = head;
                noDupList = noDupList->next;
            }
            head = head->next;
        }
        noDupList->next = NULL;
        return dummy.next;
    }
};