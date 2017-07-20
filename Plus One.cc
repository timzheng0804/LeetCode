class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        for (int i = digits.size() - 1; i >= 0 && plus != 0; --i) {
            int sum = digits[i] + plus;
            digits[i] = sum % 10;;
            plus = sum / 10;
        }
        if (plus != 0) digits.insert(digits.begin(), plus);
        return digits;
    }
};