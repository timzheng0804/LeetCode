class Solution {
public:
    void findCombination(int begin, vector<vector<int>>& ans, vector<int>& combination,
                         vector<int>& candidates, int target) {
        if (!target) {
            ans.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            if (candidates[i] > target) return;
            combination.emplace_back(candidates[i]);
            findCombination(i + 1, ans, combination, candidates, target - candidates[i]);
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) ++i;
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        findCombination(0, ans, combination, candidates, target);
        return ans;   
    }
};