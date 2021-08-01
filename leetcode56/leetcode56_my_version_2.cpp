// Runtime: 24 ms, faster than 36.39% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.8 MB, less than 22.46% of C++ online submissions for Merge Intervals.
// time complexity: O(n log n)
// space complexity: O(1)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &int1, vector<int> &int2)
             { return int1[0] < int2[0]; });

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (auto interval : intervals)
        {
            if (interval[0] > mergedIntervals.back()[1])
                mergedIntervals.push_back(interval);
            else
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
        }

        return mergedIntervals;
    }
};