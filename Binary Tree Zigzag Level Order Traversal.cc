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
    void inOrderTraversal(int level, vector<vector<int>>& treeNodes, TreeNode* root) {
        if (!root) return;
        if (treeNodes.size() == level) {
            vector<int> newLv;
            treeNodes.push_back(newLv);
        }
        treeNodes[level].push_back(root->val);
        ++level;
        inOrderTraversal(level,treeNodes,root->left);
        inOrderTraversal(level, treeNodes,root->right);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        inOrderTraversal(0, nodes, root);
        for (int i = 1; i < nodes.size(); i += 2) {
            reverse(nodes[i].begin(), nodes[i].end());
        }
        return nodes;
    }
};