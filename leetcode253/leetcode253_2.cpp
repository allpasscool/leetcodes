class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        if (n == 0) {
            return 0;
        }
        
        vector<int> start, end;
        
        // put all intervals' start and end into vectors
        for (int i = 0; i < n; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        // two pointers in the algo.:s_ptr, e_ptr
        int s_ptr = 0, e_ptr = 0;
        int used_room = 0;
        
        while (s_ptr < n) {
            // if there is a meeting that has ended by the time the meeting at 's_ptr' starts
            if (start[s_ptr] >= end[e_ptr]) {
                used_room--;
                e_ptr++;
            }
            
            // we do this irrespective of whether a room frees up or not.
            // if a room got free, then this used_room++ won't have any effect.
            // used_room would remain the same in that case. If no room was free,
            // then this would increase used_rooms
            used_room++;
            s_ptr++;
        }
        
        return used_room;
    }
};
// Runtime: 16 ms, faster than 95.41% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 12.1 MB, less than 84.85% of C++ online submissions for Meeting Rooms II.
// time complexity: O(n log n)
// space complexity: O(n log n)