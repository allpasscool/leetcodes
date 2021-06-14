class Solution {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

        for (int[] interval : intervals) {
            while (!pq.isEmpty() && interval[0] >= pq.peek()) {
                pq.poll();
            }

            pq.add(interval[1]);
            ans = Math.max(ans, pq.size());
        }

        return ans;
    }
}

// Runtime: 8 ms, faster than 30.90% of Java online submissions for Meeting
// Rooms II.
// Memory Usage: 38.5 MB, less than 85.86% of Java online submissions for
// Meeting Rooms II.
// time complexity: O(n log n)
// space complexity: O(n)