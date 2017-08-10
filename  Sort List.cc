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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* sortedList = &dummy;
        while (left || right) {
            if (!left) {
                sortedList->next = right;
                break;
            } else if (!right) {
                sortedList->next = left;
                break;
            } else if (left->val < right->val) {
                sortedList->next = left;
                left = left->next;
            } else {
                sortedList->next = right;
                right = right->next;
            }
            sortedList = sortedList->next;
        }
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        return merge(left, right);
    }
};