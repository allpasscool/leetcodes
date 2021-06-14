class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, String> freq = new HashMap<>();

        for (String w : words) {
            if (freq.get(w) == null) {
                freq.put(w, "1");
            } else {
                int num = Integer.valueOf(freq.get(w)) + 1;
                freq.put(w, String.valueOf(num));
            }
        }

        PriorityQueue<String[]> pq = new PriorityQueue<>(
                (a, b) -> (Integer.valueOf(a[1]) == Integer.valueOf(b[1]) ? b[0].compareTo(a[0])
                        : Integer.valueOf(a[1]) - Integer.valueOf(b[1])));

        for (String key : freq.keySet()) {
            pq.add(new String[] { key, freq.get(key) });

            if (pq.size() > k) {
                pq.poll();
            }
        }

        List<String> ans = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            ans.add(pq.poll()[0]);
        }
        // reverse
        for (int i = 0; i < ans.size() / 2; i++) {
            String tmp = ans.get(i);
            ans.set(i, ans.get(ans.size() - 1 - i));
            ans.set(ans.size() - 1 - i, tmp);
        }

        return ans;
    }
}

// Runtime: 7 ms, faster than 27.29% of Java online submissions for Top K
// Frequent Words.
// Memory Usage: 39 MB, less than 69.10% of Java online submissions for Top K
// Frequent Words.
// time complexity: O(n log n)
// space complexity: O(n)