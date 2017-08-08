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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> myStack;
        while (fast && fast->next) {
            myStack.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) { slow = slow->next; }
        while (slow) {
            if (myStack.top() != slow->val) {
                return false;
            }
            myStack.pop();
            slow = slow->next;
        }
        return true;
    }
};