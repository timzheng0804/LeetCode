class Solution {
public:
    void generateCombination(int k, int n, vector<vector<int>>& sol, vector<int>& temp, int start) {
        if (n == 0 && temp.size() == k) {
            sol.push_back(temp);
            return;
        }
        for (int i = start; i <= 9 && temp.size() < k; ++i) {
            temp.push_back(i);
            generateCombination(k, n - i, sol, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> temp;
        generateCombination(k, n, sol, temp, 1);
        return sol;
    }
};