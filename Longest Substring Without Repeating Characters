class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashArray[256] = { 0 };
        int startingIndice = 0, length = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (hashArray[s[i]] > startingIndice) {
                startingIndice = hashArray[s[i]];
            }
            length = max(length, i - startingIndice + 1);
            hashArray[s[i]] = i + 1;
        }
        return length;
    }
};