class Solution {
public:
    void generateAllPattern(vector<string>& ans) {
        vector<string> acc;
        for (int i = 0; i < ans.size(); ++i) {
            string brackets = ans[i];
            for (int j = 0; j < brackets.length(); ++j) {
                if (brackets[j] == '(') {
                    string s = brackets.substr(0, j + 1) + 
                        "()" + brackets.substr(j + 1);
                    acc.emplace_back(s);
                }
            }
        }
        ans.swap(acc);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        for (int i = 0; i < n; ++i) {
            generateAllPattern(ans);
            s = s + "()";
            ans.emplace_back(s);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};