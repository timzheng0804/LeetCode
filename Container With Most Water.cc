class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            maxA = max(maxA, (j - i) * min(height[i], height[j]));
            int iTemp = height[j] >= height[i] ? i + 1 : i;
            j = height[i] >= height[j] ? j - 1 : j;
            i = iTemp;
        }
        return maxA;
    }
};