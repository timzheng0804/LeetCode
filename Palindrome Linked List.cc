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
    bool recursiveCheck(ListNode* start, ListNode* end, ListNode* middle) {
        if (!start || !end) return true;
        if (start == middle) return true;
        bool rec = recursiveCheck(start->next, end, middle);
        bool compare = start->val == end->val;
        if (end->next) {
            *end = *end->next;
        }
        return compare && rec;
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast) { 
            return recursiveCheck(head, slow, slow); 
        }
        return recursiveCheck(head, slow->next, slow);
    }
};