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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> mStack;
        TreeNode* pre = root;
        while (!mStack.empty() || pre) {
            if (pre) {
                mStack.push(pre);
                pre = pre->left;
            } else {
                pre = mStack.top();
                nodes.push_back(pre->val);
                mStack.pop();
                pre = pre->right;
            }
        }
        return nodes;
    }
};