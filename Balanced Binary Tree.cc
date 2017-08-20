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
    int compare(TreeNode* root) {
        if (!root) return 0;
        int left = compare(root->left);
        if (left == -1) return left;
        int right = compare(root->right);
        if (right == -1) return right;
        if (abs(left - right) <= 1) return 1 + max(left, right);
        return -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return compare(root) != -1;
    }
};