class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) return 0; 
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            min = prices[i] < min ? prices[i] : min;
            max = prices[i] - min > max ? prices[i] - min : max;
        }
        return max;
    }
};