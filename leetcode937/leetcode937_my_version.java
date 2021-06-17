class Solution {
    public String[] reorderLogFiles(String[] logs) {

        PriorityQueue<String[]> pqLet = new PriorityQueue<>(
                (a, b) -> a[1].equals(b[1]) ? a[0].compareTo(b[0]) : a[1].compareTo(b[1]));
        Queue<String> qDig = new LinkedList<>();

        for (String log : logs) {
            if (Character.isLetter(log.charAt(log.length() - 1))) {
                int spacePos = log.indexOf(" ");
                pqLet.add(new String[] { log.substring(0, spacePos + 1), log.substring(spacePos + 1) });
            } else {
                qDig.add(log);
            }
        }

        String[] ans = new String[logs.length];

        int pos = 0;

        while (!pqLet.isEmpty()) {
            String[] log = pqLet.poll();
            ans[pos] = log[0] + log[1];
            pos++;
        }
        while (!qDig.isEmpty()) {
            ans[pos] = qDig.poll();
            pos++;
        }

        return ans;
    }
}

// Runtime: 3 ms, faster than 86.72% of Java online submissions for Reorder Data
// in Log Files.
// Memory Usage: 38.8 MB, less than 97.73% of Java online submissions for
// Reorder Data in Log Files.
// time complexity: O(n log n)
// space complexity: O(n)