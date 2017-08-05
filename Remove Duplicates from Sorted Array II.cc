class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int curPos = 0;
        int n;
        for (int i = 0; i < nums.size(); ++i) {
            n = nums[i];
            swap(nums[i], nums[curPos++]);
            if (i + 1 < nums.size() && n == nums[i + 1]) {
                swap(nums[++i], nums[curPos++]);
                while (i < nums.size() && n == nums[i + 1]) ++i;
            }
        }
        return curPos;
    }
};