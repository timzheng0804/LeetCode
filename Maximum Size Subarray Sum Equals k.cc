class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hTable;
        int curSum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum == k) {
                maxLen = i + 1;    
            } else if (hTable.find(curSum - k) != hTable.end()) {
                maxLen = max(maxLen, i - hTable[curSum - k]);
            }
            if (hTable.find(curSum) == hTable.end()) {
                hTable[curSum] = i;    
            }
        }
        return maxLen;
    }
};