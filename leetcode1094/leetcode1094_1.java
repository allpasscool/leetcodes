class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> timestamp = new TreeMap<>();
        for (int[] trip : trips) {
            int startPassenger = timestamp.getOrDefault(trip[1], 0) + trip[0];
            timestamp.put(trip[1], startPassenger);

            int endPassenger = timestamp.getOrDefault(trip[2], 0) - trip[0];
            timestamp.put(trip[2], endPassenger);
        }
        int usedCapacity = 0;
        for (int passengerChange : timestamp.values()) {
            usedCapacity += passengerChange;
            if (usedCapacity > capacity) {
                return false;
            }
        }
        return true;
    }
}

// Runtime: 17 ms, faster than 5.95% of Java online submissions for Car Pooling.
// Memory Usage: 41.6 MB, less than 11.46% of Java online submissions for Car Pooling.
// time complexity: O(n log n)
// space complexity: O(n)