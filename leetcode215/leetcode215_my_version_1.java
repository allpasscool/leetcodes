class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : nums) {
            pq.add(num);

            if (pq.size() > (n + 1 - k)) {
                pq.poll();
            }
        }

        return pq.poll();
    }
}

// Runtime: 3 ms, faster than 70.09% of Java online submissions for Kth Largest
// Element in an Array.
// Memory Usage: 39.2 MB, less than 69.54% of Java online submissions for Kth
// Largest Element in an Array.
// time complexity: O(n log (n - k))
// space complexity: O(n - k)