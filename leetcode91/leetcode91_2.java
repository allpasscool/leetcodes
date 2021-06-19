class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }

        int n = s.length();
        int twoBack = 1;
        int oneBack = 1;
        for (int i = 1; i < n; i++) {
            int current = 0;
            if (s.charAt(i) != '0') {
                current = oneBack;
            }
            int twoDigit = Integer.parseInt(s.substring(i - 1, i + 1));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += twoBack;
            }

            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
}

// solution 3
// Runtime: 1 ms, faster than 93.45% of Java online submissions for Decode Ways.
// Memory Usage: 37.7 MB, less than 33.06% of Java online submissions for Decode
// Ways.
// time complexity: o(n)
// space complexity: O(1)