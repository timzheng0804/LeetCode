class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int firstIndex = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                firstIndex = i;
                break;
            }
        }
        if (firstIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > firstIndex; --i) {
            if (nums[i] > nums[firstIndex]) {
                swap(nums[firstIndex], nums[i]);
                reverse(nums.begin() + firstIndex + 1, nums.end());
                break;
            }
        }
    }
};