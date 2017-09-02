class Solution {
public:
    
    void generateSubsets(vector<int>& nums, vector<vector<int>>& allSubsets, vector<int>& temp, int index) {
        allSubsets.push_back(temp);
        for (int i = index; i < nums.size(); ++i) {
            vector<int> clone = temp;
            clone.push_back(nums[i]);
            generateSubsets(nums, allSubsets, clone, i + 1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> temp;
        generateSubsets(nums, allSubsets, temp, 0);
        return allSubsets;
    }
};