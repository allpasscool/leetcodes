class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>> pq;
        int n = growTime.size();

        for (int i = 0; i < n; i++)
        {
            pair<int, int> item(growTime[i], plantTime[i]);
            pq.push(item);
        }
        int finishedDay = 0;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            finishedDay = max(cur + pq.top().second + pq.top().first, finishedDay);
            cur += pq.top().second;
            pq.pop();
        }

        return finishedDay;
    }
};

// Runtime: 352 ms, faster than 79.28% of C++ online submissions for Earliest Possible Day of Full Bloom.
// Memory Usage: 168.6 MB, less than 40.51% of C++ online submissions for Earliest Possible Day of Full Bloom.
// time complexity: O(n log n)
// space complexity: O(n)
// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/discuss/1676833/C%2B%2B-Largest-Growing-Time-First-with-Illustrations