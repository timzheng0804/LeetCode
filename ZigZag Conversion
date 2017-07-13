class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> table (numRows, "");
        int currentRow = 0, step = 0;
        for (int i = 0; i < s.length(); ++i) {
            table[currentRow] += s[i];
            if (currentRow == 0) {
                step = 1;
            } else if (currentRow == numRows -1) {
                step = -1;
            }
            currentRow += step;
        }
        string acc = "";
        for (int i = 0; i < table.size(); ++i) {
            acc += table[i] != "" ? table[i] : "";
        }
        return acc;
    }
};