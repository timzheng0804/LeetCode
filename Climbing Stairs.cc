class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int pre = 0;
        int next = 1;
        for (int i = 1; i <= n; ++i) {
            next += pre;
            pre = next - pre;
        }
        return next;
    }
};