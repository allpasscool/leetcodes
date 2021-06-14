class Solution {
    public String reorganizeString(String s) {
        Map<Character, Integer> alphas = new HashMap<>();

        for (char c : s.toCharArray()) {
            if (alphas.get(c) == null) {
                alphas.put(c, 1);
            } else {
                alphas.put(c, alphas.get(c) + 1);
            }
        }

        StringBuilder ans = new StringBuilder();
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());

        // add all hashmap pairs into priority queue. sorted by number in decending
        // order
        for (Map.Entry<Character, Integer> entry : alphas.entrySet()) {
            pq.add(entry);
        }

        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> cur = pq.poll();

            // no more this letter
            if (cur.getValue() == 0)
                continue;

            // cur is same as the last letter of ans
            // for example
            // ans: aba cur: a:3
            // add next letter first
            if (ans.length() > 0 && ans.charAt(ans.length() - 1) == cur.getKey()) {
                // fail. only the same letter as the last letter of ans left
                // can't find valid answer
                if (pq.isEmpty())
                    return "";

                Map.Entry<Character, Integer> tmp = pq.poll();
                ans.append(tmp.getKey());
                tmp.setValue(tmp.getValue() - 1);
                pq.add(tmp);
            } else {
                ans.append(cur.getKey());
                cur.setValue(cur.getValue() - 1);
            }

            pq.add(cur);
        }

        return ans.toString();
    }
}
// reference leetcode 692, sol 2

// Runtime: 5 ms, faster than 30.64% of Java online submissions for Reorganize
// String.
// Memory Usage: 38.7 MB, less than 27.84% of Java online submissions for
// Reorganize String.
// time complexity: O(n log n)
// space complexity: O(n)