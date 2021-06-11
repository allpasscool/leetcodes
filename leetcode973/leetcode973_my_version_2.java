class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // PriorityQueue<int[][]> heap = new PriorityQueue<int[][]>((a, b) -> {
        // if (b[0] * b[0] + b[1] * b[1] > a[0] * a[0] + a[1] * a[1]) {
        // return 1; // b beofre a
        // } else if (b[0] * b[0] + b[1] * b[1] < a[0] * a[0] + a[1] * a[1]) {
        // return -1; // a before b
        // } else {
        // return 0; // no change
        // }
        // });
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(
                (a, b) -> ((b[0] * b[0] + b[1] * b[1]) - (a[0] * a[0] + a[1] * a[1])));

        for (int[] point : points) {
            pq.add(point);

            // at most k distance in pq
            if (pq.size() > k) {
                pq.poll();
            }
        }

        int[][] ans = new int[k][2];

        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll();
        }

        return ans;
    }
}

// Runtime: 35 ms, faster than 25.88% of Java online submissions for K Closest
// Points to Origin.
// Memory Usage: 47.2 MB, less than 80.31% of Java online submissions for K
// Closest Points to Origin.
// time complexity: O(n log k)
// space complexity: O(n)