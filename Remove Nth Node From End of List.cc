class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int difference = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                int front = j + 1;
                int end = nums.size() - 1;
                while (front < end) {
                    int threeSum = nums[j] + nums[front] + nums[end];
                    if (threeSum < difference) ++front;
                    else if (threeSum > difference) --end;
                    else {
                        vector<int> sum = { nums[i], nums[j], nums[front], nums[end]};
                        ans.emplace_back(sum);
                        while (front < end && nums[front] == sum[2]) front++;
                        while (front < end && nums[end] == sum[3]) end--;
                    }
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1]) ++j;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return ans;
    }
};