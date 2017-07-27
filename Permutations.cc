class Solution {
public:
    void generatePermutations(vector<vector<int>>& ans, vector<int>& nums) {
        int firstIndex = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                firstIndex = i;
                break;
            }    
        }
        if (firstIndex == -1) {
            return;
        }
        for (int i = nums.size() - 1; i > firstIndex; --i) {
            if (nums[i] > nums[firstIndex]) {
                swap(nums[firstIndex], nums[i]);
                reverse(nums.begin() + firstIndex + 1, nums.end());
                ans.emplace_back(nums);
                break;
            }
        }
        generatePermutations(ans, nums);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.emplace_back(nums);
        generatePermutations(ans, nums);
        return ans;
    }
};