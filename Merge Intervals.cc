/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedInterval;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });        
        for (int i = 0; i < intervals.size();) {
            int largestRange = intervals[i].end;
            int index = i + 1;
            while (index < intervals.size() && intervals[index].start <= largestRange) {
                largestRange = max(largestRange, intervals[index].end);
                ++index;
            }
            mergedInterval.push_back(Interval(intervals[i].start, largestRange));
            i = index;
        }
        return mergedInterval;
    }
};