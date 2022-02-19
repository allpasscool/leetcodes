class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals), comp());

        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(intervals[i][1], end);
            }
            else if (intervals[i][0] > end)
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});
        return ans;
    }

private:
    struct comp
    {
        bool operator()(vector<int> const &i1, vector<int> const &i2)
        {
            return (i1[0] < i2[0]) || ((i1[0] == i2[0]) && i1[1] < i2[1]);
        }
    };
};

// Runtime: 36 ms, faster than 63.67% of C++ online submissions for Merge Intervals.
// Memory Usage: 19 MB, less than 47.53% of C++ online submissions for Merge Intervals.
// time complexity: O(n log n)
// space complexity: O(1)