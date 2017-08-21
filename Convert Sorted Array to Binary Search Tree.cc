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
    TreeNode* createBST(vector<int>& nums, int start, int end) {
        if (end < start) return NULL;
        int mid = (end - start) / 2 + start;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createBST(nums, start, mid - 1);
        node->right = createBST(nums,mid + 1, end);
        return node;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
};