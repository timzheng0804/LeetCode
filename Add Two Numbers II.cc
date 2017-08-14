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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> first;
        stack<int> second;
        int extra = 0;
        ListNode* sum = NULL;
        while (l1) {
            first.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            second.push(l2->val);
            l2 = l2->next;
        }
        while (!first.empty() || !second.empty() || extra) {
            int val = extra;
            val += first.empty() ? 0 : first.top();
            val += second.empty() ? 0 : second.top();
            extra = val / 10;
            ListNode* newVal = new ListNode(val % 10);
            newVal->next = sum;
            sum = newVal;              
            if (!first.empty()) { first.pop(); }
            if (!second.empty()) { second.pop(); }
        }
        return sum;
    }
};