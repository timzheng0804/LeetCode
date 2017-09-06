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
    void generateSum(TreeNode* root, int& sum, int val) {
        if (!root) return;
        val = val * 10 + root->val;
        if (!root->left && !root->right) {
            sum += val;
        }
        generateSum(root->left, sum, val);
        generateSum(root->right, sum, val);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        generateSum(root, sum, 0);
        return sum;
    }
};