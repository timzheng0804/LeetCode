class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            int front = i + 1;
            int end = nums.size() - 1;
            while (front < end) {
                int twoSum = nums[front] + nums[end];
                if (twoSum < target) {
                    ++front;
                } else if (twoSum > target) {
                    --end;
                } else {
                    vector<int> three = { nums[i], nums[front], nums[end] };
                    sums.emplace_back(three);
                    while (front < end && nums[front] == three[1] ) ++front;
                    while (front < end && nums[end] == three[2]) --end;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return sums;
    }
};