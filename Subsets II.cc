class Solution {
public:
    void generateSubsets(vector<int>& nums, vector<vector<int>>& solution, vector<int>& temp, int index) {
        solution.push_back(temp);
        for (int i = index; i < nums.size(); ++i) {
            vector<int> clone = temp;
            clone.push_back(nums[i]);
            generateSubsets(nums, solution, clone, i + 1);
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        vector<int> temp;
        generateSubsets(nums, solution, temp, 0);
        return solution;
    }
};