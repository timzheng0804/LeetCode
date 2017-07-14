class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int difference = INT_MAX;
        if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int front = i + 1;
            int end = nums.size() - 1;
            while (front < end) {
                int threeSum = nums[i] + nums[front] + nums[end];
                int dif = abs(target - threeSum);
                if (dif < difference) {
                    ans = threeSum, difference = dif;
                    if (ans == target) return ans;
                }
                threeSum > target ? --end : ++front;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return ans;
    }
};