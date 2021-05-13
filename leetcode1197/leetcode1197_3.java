class Solution {

    private int dfs(int x, int y, Map<String, Integer> memo) {
        String key = x + "," + y;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        if (x + y == 0) {
            return 0;
        } else if (x + y == 2) {
            return 2;
        } else {
            int first_road = dfs(Math.abs(x - 1), Math.abs(y - 2);
            int second_road = dfs(Math.abs(x - 2), Math.abs(y - 1));
            Integer ret = Math.min(first_road, second_road, memo) + 1;
            memo.put(key, ret);
            return ret;
        }
    }

    public int minKnightMoves(int x, int y) {
        Map<String, Integer> memo = new HashMap<>();
        return dfs(Math.abs(x), Math.abs(y));
    }
}

// Runtime: 13 ms, faster than 94.45% of Java online submissions for Minimum Knight Moves.
// Memory Usage: 39.1 MB, less than 86.03% of Java online submissions for Minimum Knight Moves.
// time complexity: O(x * y)
// space complexity: O(x * y)