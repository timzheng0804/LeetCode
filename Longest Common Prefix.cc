class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string s = strs[0];
        int len = 0;
        for (len = 0; len < s.length(); ++len) {
            for (int j = 1; j < strs.size(); ++j) {
                if (s[len] != (strs[j])[len]) {
                    return s.substr(0, len);
                }
            }
        }    
        return s.substr(0, len);
    }
};