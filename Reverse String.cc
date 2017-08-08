class Solution {
public:
    string reverseString(string s) {
        int tail = s.length() - 1;
        for (int i = 0; i < s.length() / 2; ++i) {
            swap(s[i], s[tail - i]);
        }
        return s;
    }
};