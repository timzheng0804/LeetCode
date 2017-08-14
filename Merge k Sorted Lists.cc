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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* mergedList = &dummy;
        while (l1 || l2) {
            if (!l1) { mergedList->next = l2; l2 = l2->next; break; }
            else if (!l2) { mergedList->next = l1; l1 = l1->next; break; }
            else if (l1->val < l2->val) { mergedList->next = l1; l1 = l1->next; }
            else { mergedList->next = l2; l2 = l2->next; }
            mergedList = mergedList->next;
        }
        return dummy.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        vector<ListNode*> mergedList;
        if (lists.size() % 2 != 0) { mergedList.push_back(lists[lists.size() - 1]); }
        for (int i = 0; i < lists.size() - 1; i += 2) {
            ListNode* merged = mergeTwoList(lists[i], lists[i + 1]);
            mergedList.push_back(merged);
        }
        return mergeKLists(mergedList);
    }
};