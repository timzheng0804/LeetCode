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
    void findSuccessor(TreeNode* root, int val, TreeNode* &next) {
        if (!root) return;
        findSuccessor(root->left, val, next);
        if (next) return;
        if (root->val > val) {
            next = root;
            return;
        }
        findSuccessor(root->right, val, next);
    }
    
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* next = NULL;
        findSuccessor(root, p->val, next);
        return next;
    }
};