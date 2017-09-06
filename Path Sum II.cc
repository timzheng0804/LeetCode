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
    void findPath(vector<vector<int>>& sol, vector<int>& temp, int sum, TreeNode* root) {
        if (!root) return;
        temp.push_back(root->val);
        sum -= root->val;
        if (!sum && !root->left && !root->right) {
            sol.push_back(temp);
            temp.pop_back();
            return;
        }
        findPath(sol, temp, sum, root->left);
        findPath(sol, temp, sum, root->right);
        temp.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> sol;
        vector<int> temp;
        findPath(sol, temp, sum, root);
        return sol;
    }
};