class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> possibleAns;
        if (digits == "") return possibleAns;
        possibleAns.emplace_back("");
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            int digit = digits[i] - '0';
            if (digit < 0 || digit > 9) break;
            vector<string> temp;
            for (int j = 0; j < mapping[digit].length(); ++j) {
                for (int k = 0; k < possibleAns.size(); ++k) {
                    temp.emplace_back(possibleAns[k] + mapping[digit][j]);
                }
            }
            possibleAns = temp;
        }
        return possibleAns;
    }
};