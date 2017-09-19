class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> list (nums.size() + 2, -1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= nums.size()) {
                list[nums[i]] = nums[i];
            }
        }
        for (int i = 1; i < list.size(); ++i) {
            if (list[i] != i) {
                return i;
            }
        }
        return 1;
    }
};