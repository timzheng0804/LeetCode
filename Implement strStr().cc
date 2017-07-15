class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.length();
        int haystackSize = haystack.length();
        if (haystack == needle) return 0;
        for (int i = 0; i < haystackSize - needleSize + 1; ++i) {
            bool same = true;
            for (int j = 0; j < needleSize; ++j) {
                if (haystack[i + j] != needle[j]) { same = false; break; }
            }
            if (same) return i;
        }
        return -1;
    }
};