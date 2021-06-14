class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        // Check for the base case. If there are no intervals, return 0
        if (n == 0) {
            return 0;
        }

        Integer[] start = new Integer[n];
        Integer[] end = new Integer[n];

        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        // Sort the intervals by start time
        // 1.
        // Arrays.sort(
        // start,
        // new Comparator<Integer>() {
        // public int compare(Integer a, Integer b) {
        // return a - b;
        // }
        // });
        // 2.
        // Arrays.sort(start, (a, b) -> a - b);
        // 3.
        Arrays.sort(start);

        // Sort the intervals by end time
        // 1.
        // Arrays.sort(
        // end,
        // new Comparator<Integer>() {
        // public int compare(Integer a, Integer b) {
        // return a - b;
        // }
        // });
        // 2.
        // Arrays.sort(end, (a, b) -> a - b);
        // 3.
        Arrays.sort(end);

        // The two pointers in the algorithm: e_ptr and s_ptr.
        int startPointer = 0, endPointer = 0;

        // Variables to keep track of maximum number of rooms used.
        int usedRooms = 0;

        // Iterate over intervals.
        while (startPointer < intervals.length) {

            // If there is a meeting that has ended by the time the meeting at
            // `start_pointer` starts
            if (start[startPointer] >= end[endPointer]) {
                usedRooms -= 1;
                endPointer += 1;
            }

            // We do this irrespective of whether a room frees up or not.
            // If a room got free, then this used_rooms += 1 wouldn't have any effect.
            // used_rooms would
            // remain the same in that case. If no room was free, then this would increase
            // used_rooms
            usedRooms += 1;
            startPointer += 1;

        }

        return usedRooms;
    }
}

// Runtime: 6 ms, faster than 77.89% of Java online submissions for Meeting
// Rooms II.
// Memory Usage: 39.5 MB, less than 31.53% of Java online submissions for
// Meeting Rooms II.
// time complexity: O(n log n)
// space complexity: O(n)