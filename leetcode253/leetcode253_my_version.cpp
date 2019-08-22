class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int min_room = 0;
        map<int, int> time_and_room;
        int n = intervals.size();
        
        // find all start and end
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (time_and_room.find(start) == time_and_room.end()) {
                time_and_room[start] = 0;
            }
            if (time_and_room.find(end) == time_and_room.end()) {
                time_and_room[end] = 0;
            }
        }
        
        // go through all intervals
        for (auto& interval: intervals) {
            int start = interval[0], end = interval[1];
            // add rooms
            for (auto& it: time_and_room) {
                if (it.first >= start && it.first < end) {
                    it.second++;
                    min_room = max(min_room, it.second);
                }
                else if (it.first > end) {
                    break;
                }
            }
        }
        
        return min_room;
    }
};
// Runtime: 1324 ms, faster than 6.35% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 13.6 MB, less than 33.33% of C++ online submissions for Meeting Rooms II.
// time complexity: O(n^2)
// space complexity: O(n)