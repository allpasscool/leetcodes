class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] timestamp = new int[1001];
        for (int[] trip : trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        int usedCapacity = 0;
        for (int number : timestamp) {
            usedCapacity += number;
            if (usedCapacity > capacity) {
                return false;
            }
        }
        return true;
    }
}

// Runtime: 2 ms, faster than 74.98% of Java online submissions for Car Pooling.
// Memory Usage: 41.6 MB, less than 14.26% of Java online submissions for Car Pooling.
// time complexity: O(max(n, 1001))
// space complexity: O(1001, 1)