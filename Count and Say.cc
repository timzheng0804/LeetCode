class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string acc = "";
            int pos = 0;
            while (pos < s.length()) {
                int nextPos = pos + 1;
                int count = 1;
                while (nextPos < s.length() && s[pos] == s[nextPos]) { nextPos++; ++count; }
                acc += to_string(count) + s[pos];
                pos = nextPos;
            }
            s = acc;
        }
        return s;
    }
};