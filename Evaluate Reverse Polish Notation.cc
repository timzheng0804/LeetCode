class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expStack;
        for (int i = 0; i < tokens.size(); ++i) {
            string notation = tokens[i];
            if (notation.length() > 1 || isdigit(notation[0])) expStack.push(stoi(notation));
            else {
                int val2 = expStack.top(); expStack.pop();
                int val1 = expStack.top(); expStack.pop();
                switch(notation[0]) {
                    case '*': val1 *= val2; break;
                    case '/': val1 /= val2; break;
                    case '-': val1 -= val2; break;
                    case '+': val1 += val2; break;
                    default: break;
                }
                expStack.push(val1);
            }
        }
        return expStack.top();
    }
};