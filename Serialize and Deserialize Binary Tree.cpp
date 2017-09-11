/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        stack<TreeNode*> stack;
        while (root || !stack.empty()) {
            if (root) {
                s += to_string(root->val) + " ";
                stack.push(root);
                root = root->left;
            } else {
                s += "- ";
                root = stack.top()->right;
                stack.pop();
            }
        }
        return s;
    }
    
    TreeNode* helper(int& index, istringstream& ss) {
        string s;
        ss >> s;
        if (s == "" || s  == "-") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(s)); 
        root->left = helper(index, ss);
        root->right = helper(index, ss);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        istringstream ss (data);
        return helper(index, ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));