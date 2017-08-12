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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* slow = head, *fast = head->next;
        ListNode* reverse = NULL;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        while (fast) {
            ListNode* next = fast->next;
            fast->next = reverse;
            reverse = fast;
            fast = next;
        }        
        while (head && reverse) {
            ListNode* next1 = head->next;
            ListNode* next2 = reverse->next;
            head->next = reverse;
            reverse->next = next1;
            head = next1;
            reverse = next2;
        }
    }
};