class Solution {
public:
    int rob(vector<int>& nums) {
        int i = 0;
        int e = 0;
        int temp;
        for (int k = 0; k < nums.size(); ++k) {
            temp = i;
            i = nums[k] + e;
            e = max(temp, e);
        }
        return max(i, e);
    }
};