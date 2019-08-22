class Solution {
private:
    static bool comp(const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    }
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // check for the base case. If there is no interval, return 0
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        
        // default heap is max heap
        // to change to min heap,  priority_queue <Type, vector<Type>, ComparisonType > min_heap;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // sort intevals base on start time
        sort(intervals.begin(), intervals.end(), comp);
        
        // add the first meeting
        pq.push(intervals[0][1]);
        
        // iterate the rest intervals
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            // if the room due to free up the earliest is free, assign that room to this meeting.
            if (pq.top() <= start) {
                pq.pop();
            }
            
            // if a new room is to be assigned, then also we add to the heap,
            // if an old room is allocated, then also we have to add to the heap with updated end tiem
            pq.push(end);
        }
        
        // the size of the heap tells us the minimum rooms required for all the meetings
        return pq.size();
    }
};
// Runtime: 20 ms, faster than 75.25% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Meeting Rooms II.
// time complexity: O(n log n)
// space complexity: O(n)