class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int begin = 1, end = x;
        while (begin <= end) {
            int mid = (end - begin) / 2 + begin;
            int ans = x / mid;
            if (ans == mid) {
                return mid;
            } else if (ans > mid) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return begin - 1;
    }
};