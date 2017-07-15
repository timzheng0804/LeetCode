class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0, exchanged = 0, end = nums.size() - 1;
        while (front <= end) {
            if (nums[front] == val) {
                while (front < end && nums[end] == val) { --end; ++exchanged; }
                nums[front] = nums[end--];
                ++exchanged;
            }
            ++front;
        }
        return nums.size() - exchanged;
    }
};