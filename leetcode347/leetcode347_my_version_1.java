class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            if (freq.get(num) == null) {
                freq.put(num, 1);
            } else {
                freq.put(num, freq.get(num) + 1);
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[1] - b[1]));

        for (Integer key : freq.keySet()) {
            pq.add(new int[] { key, freq.get(key) });

            if (pq.size() > k) {
                pq.poll();
            }
        }

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll()[0];
        }

        return ans;
    }
}

// Runtime: 11 ms, faster than 45.38% of Java online submissions for Top K
// Frequent Elements.
// Memory Usage: 41.3 MB, less than 88.85% of Java online submissions for Top K
// Frequent Elements.
// time complexity: O(n log k)
// space complexity: O(n + k)