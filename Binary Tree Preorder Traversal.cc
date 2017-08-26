/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> myStack;
        TreeNode* pre = root;
        while (!myStack.empty() || pre) {
            if (pre) {
                preorder.push_back(pre->val);
                myStack.push(pre);
                cout << pre->val << endl;
                pre = pre->left;
            } else {
                pre = myStack.top();
                myStack.pop();
                pre = pre->right;
            }
            
        }
        return preorder;
    }
};