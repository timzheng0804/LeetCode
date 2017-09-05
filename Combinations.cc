class Solution {
public:
    void combine(vector<vector<int>>& sol, vector<int>& temp, int n, int index, int k) {
        if (!k) {
            sol.push_back(temp);
            return;
        }
        for (int i = index; i <= n - k + 1; ++i) {
            temp.push_back(i);
            combine(sol, temp, n, i + 1, k - 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> sol;
        combine(sol, temp, n, 1, k);
        return sol;
    }
};