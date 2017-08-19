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
    int findLength(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(findLength(root->left), findLength(root->right));
    }
    
    void addLevelNodes(int level, vector<vector<int>>& nodes, TreeNode* root) {
        if (!root) return;
        nodes[level].push_back(root->val);
        --level;
        addLevelNodes(level, nodes, root->left);
        addLevelNodes(level, nodes, root->right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int length = findLength(root);
        vector<vector<int>> nodes (length, vector<int>());
        addLevelNodes(length - 1, nodes,root);
        return nodes;
    }
};