class Solution {
public:
    
    int superBinarySearch(int begin, int end, vector<int>& nums, int target) {
        if (begin > end) return 0;
        int mid = (end - begin) / 2 + begin;
        if (nums[mid] == target) {
            return mid + 1;
        }
        return superBinarySearch(mid + 1, end, nums, target) + superBinarySearch(begin, mid - 1,nums, target);
        
    }
    
    int search(vector<int>& nums, int target) {
        int index = superBinarySearch(0, nums.size() - 1, nums, target);
        return (index == 0 ? -1 : index - 1);
    }
};