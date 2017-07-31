class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int cur = nums[0];
        int beginIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            cur += nums[i];
            cur = nums[i] > cur ? nums[i] : cur;
            maxSum = cur > maxSum ? cur : maxSum;
        }
        return maxSum > cur ? maxSum : cur;
    }
};