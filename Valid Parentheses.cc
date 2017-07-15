class Solution {
public:
    bool isValid(string s) {
        stack<int> bracketStack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            } else {
                if (bracketStack.empty()) return false;
                if (c == ')' && bracketStack.top() != '(') return false;
                if (c == '}' && bracketStack.top() != '{') return false;
                if (c == ']' && bracketStack.top() != '[') return false;
                bracketStack.pop();
            }
        }
        return bracketStack.empty();
    }
};