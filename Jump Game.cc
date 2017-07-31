class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = nums.size() - 1;
        // Find first index that reaches last index
        while (index >= 0 && nums[index] + index < nums.size() - 1) --index;
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] + i >= index) {
                index = i;
            }
        }
        return index == 0;
    }
};