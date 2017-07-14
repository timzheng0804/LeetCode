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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode* acc = head;
        vector<ListNode*> listNodeCollector;
        while (acc) {
            listNodeCollector.push_back(acc);
            acc = acc->next;
        }
        if (n == listNodeCollector.size()) {
            return head->next;
        }
        int len = listNodeCollector.size();
        listNodeCollector[len - n - 1]->next = listNodeCollector[len - n]->next;
        return head;
    }
};