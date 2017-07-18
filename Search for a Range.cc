class Solution {
public:
    void binarySearch(vector<int>& nums, int target, int begin, int end,
                      vector<int>& range) {
        if (begin > end) return;
        int medium = (begin + end) / 2;
        if (nums[medium] == target) {
            range[0] = (range[0] == -1) || medium < range[0] ? medium : range[0];
            range[1] = (range[1] == -1) || medium > range[1] ? medium : range[1];
            binarySearch(nums, target, begin, medium - 1, range);
            binarySearch(nums, target, medium + 1, end, range);
        } else if (nums[medium] > target) {
            binarySearch(nums, target, begin, medium - 1, range);
        } else {
            binarySearch(nums, target, medium + 1, end, range);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        vector<int> ans = {-1, -1};
        binarySearch(nums, target, begin, end, ans);
        return ans;
    }
};