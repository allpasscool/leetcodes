public class Solution {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> counts = new HashMap<Character, Integer>();
        for (char t : tasks) {
            counts.put(t, counts.getOrDefault(t, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a, b) -> b - a);
        pq.addAll(counts.values());

        int alltime = 0;
        int cycle = n + 1;

        while (!pq.isEmpty()) {
            int worktime = 0;
            List<Integer> tmp = new ArrayList<Integer>();

            for (int i = 0; i < cycle; i++) {
                if (!pq.isEmpty()) {
                    tmp.add(pq.poll());
                    worktime++;
                }
            }

            for (int cnt : tmp) {
                if (cnt - 1 > 0) {
                    pq.offer(cnt - 1);
                }
            }

            alltime += !pq.isEmpty() ? cycle : worktime;
        }

        return alltime;
    }
}

// Runtime: 24 ms, faster than 30.45% of Java online submissions for Task
// Scheduler.
// Memory Usage: 40.3 MB, less than 54.27% of Java online submissions for Task
// Scheduler.
// time complexity: O(n log n)
// space complexity: O(n)
// https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue