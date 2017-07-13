class Solution {
public:
    int reverse(int x) {
        int res;
        while (x) {
            int temp = res * 10 + x % 10;
            if (temp / 10 != res) { return 0; }
            res = temp;
            x = x / 10;
        }
        return res;
    }
};