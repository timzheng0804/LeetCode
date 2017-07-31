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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL) return head;
        vector<ListNode*> list;
        ListNode* acc = head;
        while (acc) {
            list.push_back(acc);
            acc = acc->next;
        }
        if (k > list.size()) k %= list.size();
        if (k == list.size() || k == 0) return head;
        else {
            list[list.size() - 1]->next = list[0];
            list[list.size() - k - 1]->next = NULL;
        }
        return list[list.size() - k];
    }
};