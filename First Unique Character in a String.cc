class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size() - 1;
        while (target != numbers[begin] + numbers[end]) {
            if (numbers[begin] + numbers[end] < target) {
                begin++;
            } else {
                end--;
            }
        }
        return vector<int>({ begin + 1, end + 1 });
    }
};