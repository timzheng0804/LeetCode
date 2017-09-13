class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (end > start) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
    
    void findPalindrome(string& s, vector<vector<string>>& palindromeSet, vector<string>& temp, int index) {
        if (index == s.length()) {
            palindromeSet.push_back(temp);
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            if (isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                findPalindrome(s, palindromeSet, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromeSet;
        vector<string> temp;
        findPalindrome(s, palindromeSet, temp, 0);
        return palindromeSet;
    }
    
};