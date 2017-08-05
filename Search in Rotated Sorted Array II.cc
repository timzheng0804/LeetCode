class Solution {
public:
    bool binarySearch(int begin, int end, int target, vector<int>& nums) {
        if (begin > end) return false;
        int mid = (end - begin) / 2 + begin;
        if (target == nums[mid]) return true;
        return binarySearch(mid + 1, end, target, nums) ||  binarySearch(begin, mid - 1, target, nums);
    }
    
    bool search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        return binarySearch(begin, end, target, nums);
    }
};