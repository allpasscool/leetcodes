class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> m = new TreeMap<>();
        for (int[] t : trips) {
            m.put(t[1], m.getOrDefault(t[1], 0) + t[0]);
            m.put(t[2], m.getOrDefault(t[2], 0) - t[0]);
        }
        for (int v : m.values()) {
            capacity -= v;
            if (capacity < 0) {
                return false;
            }
        }
        return true;
    }
}

// Runtime: 17 ms, faster than 5.95% of Java online submissions for Car Pooling.
// Memory Usage: 41.9 MB, less than 6.24% of Java online submissions for Car Pooling.
// time complexity: O(n log n)
// space complexity: O(n)
// https://leetcode.com/problems/car-pooling/discuss/317610/JavaC%2B%2BPython-Meeting-Rooms-III