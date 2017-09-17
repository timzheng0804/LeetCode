class Solution {
public:
    int trap(vector<int>& height) {
        int sumTrapped = 0;
        for (int i = 0; i < height.size();) {
            int waterTrapped = 0;
            int currentHeight = height[i++];
            while (i < height.size() && currentHeight > height[i]) {
                waterTrapped += currentHeight - height[i++];
            }
            if (i < height.size()) {
                sumTrapped += waterTrapped;
            }
        }
        for (int i = height.size() - 1; i >= 0;) {
            int waterTrapped = 0;
            int currentIndex = i;
            int currentHeight = height[i--];
            while (i < height.size() && currentHeight >= height[i]) {
                waterTrapped += currentHeight - height[i--];
            }
            if (i >= 0) {
                sumTrapped += waterTrapped;
            }
        }
        return sumTrapped;
    }
};