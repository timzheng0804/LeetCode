/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddDummy(0), evenDummy(0);
        ListNode* odd = &oddDummy, *even = &evenDummy;
        for (int i = 1; head; ++i) {
            if (i % 2 == 0) {
                even = even->next = head;
            } else {
                odd = odd->next = head;
            }
            head = head->next;
        }
        odd->next = evenDummy.next;
        even->next = NULL;
        return oddDummy.next;
    }
};