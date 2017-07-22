class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int count = 0;
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> ans;
        for (string s : strs) {
            sort(s.begin(), s.end());
            hashMap[s].push_back(strs[count++]);
        }
        for (auto s : hashMap) {
            ans.push_back(s.second);
        }
        return ans;
    }
};