class Solution {
    public int climbStairs(int n) {
        int[] ways = new int[n + 1]; // there are ways[n] ways to reach n
        ways[1] = 1;
        if (n <= 1)
            return ways[n];

        ways[2] = 2;

        for (int i = 3; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n];
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Climbing
// Stairs.
// Memory Usage: 35.6 MB, less than 74.92% of Java online submissions for
// Climbing Stairs.
// time complexity: O(n)
// space complexity: O(n)