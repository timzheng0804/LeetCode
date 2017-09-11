class Solution {
public:
    int parition(vector<int>& nums, int begin, int end, int pivot) {
        swap(nums[begin], nums[pivot]);
        int i = begin + 1, j = end;
        while (true) {
            while (nums[i] <= nums[begin]) ++i;
            while (nums[j] > nums[begin]) --j;
            if (j < i) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[begin], nums[j]);
        return j;
    }
    
    int quickSelect(vector<int>& nums, int begin, int end, int k) {
        int pivot = (begin + end) / 2;
        int index = parition(nums, begin, end, pivot);
        if (index == nums.size() - k) {
            return nums[index];
        } else if (index < nums.size() - k) {
            return quickSelect(nums, index + 1, end, k);
        } else {
            return quickSelect(nums, begin, index - 1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};