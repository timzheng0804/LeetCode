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
    
    ListNode* recursive(ListNode* head, ListNode* reverse) {
        if (!head ) return reverse;
        ListNode* next = head->next;
        head->next = reverse;
        return recursive(next, head);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseList = NULL;
        ListNode* next;
        while (false) {
            next = head->next;
            head->next = reverseList;
            reverseList = head;
            head = next;
        }
        return recursive(head, NULL);
    }
};
};