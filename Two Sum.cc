class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                indices.emplace_back(hashMap[nums[i]]);
                indices.emplace_back(i);
                break;
            }
            int adder = target - nums[i];
            hashMap[adder] = i;
        }
        return indices;
    }
};