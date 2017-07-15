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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = new ListNode(-1);
        ListNode* beforeHead = mergedList;
        while (l1 || l2) {
            if (!l1) { mergedList->next = l2; l2 = l2->next; }
            else if (!l2) { mergedList->next = l1; l1 = l1->next;}
            else if (l1->val < l2->val) { mergedList->next = l1; l1 = l1->next; }
            else { mergedList->next = l2; l2 = l2->next; }
            mergedList = mergedList->next;
        }
        return beforeHead->next;
    }
};