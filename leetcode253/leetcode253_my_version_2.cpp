// Runtime: 12 ms, faster than 96.94% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 11.7 MB, less than 84.45% of C++ online submissions for Meeting Rooms II.
// time complexity: O(n log n)
// space complexity: O(n)
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &i1, const vector<int> &i2)
             { return i1[0] < i2[0]; });

        priority_queue<int, vector<int>, greater<int>> pq;
        int maxRoom = 0;

        for (vector<int> &interval : intervals)
        {
            int start = interval[0];

            while (!pq.empty() && pq.top() <= start)
                pq.pop();

            pq.push(interval[1]);

            maxRoom = max(maxRoom, (int)pq.size());
        }

        return maxRoom;
    }
};