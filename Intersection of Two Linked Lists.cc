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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* p1 = headA, *p2 = headB;
        int aLength = 1, bLength = 1;
        while (p1->next) {
            ++aLength;
            p1 = p1->next;
        }
        while (p2->next) {
            ++bLength;
            p2 = p2->next;
        }
        if (p1 != p2) return NULL;
        p1 = aLength > bLength ? headA : headB;
        p2 = aLength > bLength ? headB : headA;
        while (aLength != bLength) {
            if (aLength > bLength) --aLength;
            else --bLength;
            p1 = p1->next;
        }
        while (p1 && p2) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};