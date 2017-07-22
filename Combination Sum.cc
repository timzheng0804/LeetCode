class Solution {
public:
    vector<vector<int>> ans;
    
    void generateSets(int begin, vector<int>& combination, 
                      int currentSum, vector<int>& candidates, int target) {
        if (currentSum == target) {
            ans.emplace_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && currentSum < target; ++i) {
            int sum = currentSum + candidates[i];
            combination.emplace_back(candidates[i]);
            generateSets(i, combination, sum, candidates, target);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        generateSets(0, combination, 0, candidates, target);
        return ans;
    }
};