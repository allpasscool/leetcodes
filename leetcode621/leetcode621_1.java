public class Solution {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> counts = new HashMap<Character, Integer>();
        for (char t : tasks) {
            counts.put(t, counts.getOrDefault(t, 0) + 1);
        }

        Pair p = new Pair("A", 1);

        PriorityQueue<Pair<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());

        for (Map.Entry<Character, Integer> task : counts.entrySet()) {
            pq.add(new Pair(task.getKey(), task.getValue()));
        }

        int alltime = 0;
        int cycle = n + 1;

        while (!pq.isEmpty()) {
            int worktime = 0;
            List<Pair<Character, Integer>> tmp = new ArrayList<>();

            for (int i = 0; i < cycle; i++) {
                if (!pq.isEmpty()) {
                    tmp.add(pq.poll());
                    worktime++;
                }
            }

            for (Pair<Character, Integer> cur : tmp) {
                if (cur.getValue() - 1 > 0) {
                    pq.offer(new Pair(cur.getKey(), cur.getValue() - 1));
                }
            }

            alltime += !pq.isEmpty() ? cycle : worktime;
        }

        return alltime;
    }
}

// Runtime: 27 ms, faster than 23.87% of Java online submissions for Task
// Scheduler.
// Memory Usage: 39.6 MB, less than 91.95% of Java online submissions for Task
// Scheduler.
// time complexity: O(n log n)
// space complexity: O(n)
// https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue