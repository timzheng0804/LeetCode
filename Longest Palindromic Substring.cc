class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int start = 0, length = 1;
        for (int i = 0; i < s.length();) {
            if (s.length() - i <= length / 2) break;
            int j = i, k = i;
            while (k < s.length() - 1 && s[k] == s[k+1]) ++k;
            i = k + 1;
            while (k < s.length() - 1 && j > 0 && s[k+1] == s[j-1] ) { ++k; --j; }
            int new_len = k - j + 1;
            if (new_len > length) { start = j; length = new_len; }
        }
        return s.substr(start, length);
    }
};