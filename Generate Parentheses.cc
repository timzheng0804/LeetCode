class Solution {
public:
    void backTrack(vector<string>& sol, string& s, int left, int right, int n) {
        if (right == n) {
            sol.push_back(s);
            return;
        }
        
        if (left < n) {
            s += "(";
            backTrack(sol, s, left + 1, right, n);
            s.pop_back();
        }
        if (right < left) {
            s += ")";
            backTrack(sol, s, left, right + 1, n);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string s = "";
        backTrack(sol, s, 0, 0, n);
        return sol;
    }
};
