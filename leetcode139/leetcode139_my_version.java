class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>();
        int longestLen = 0;

        for (String w : wordDict) {
            words.add(w);
            longestLen = Math.max(longestLen, w.length());
        }

        boolean[] dp = new boolean[s.length() + 1];
        // base case
        // ""
        dp[0] = true;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j <= longestLen; j++) {
                // dp[i] == xxxx(true) | xxxxxx
                // dp[i + j] == xxxx(true)|xxxxxx(true)
                if (dp[i] == true && (i + j <= s.length()) && words.contains(s.substring(i, i + j)) != false) {
                    dp[i + j] = true;
                }
            }
        }

        return dp[s.length()];
    }
}

// Runtime: 1 ms, faster than 99.20% of Java online submissions for Word Break.
// Memory Usage: 37.2 MB, less than 96.63% of Java online submissions for Word
// Break.
// time complexity: O(n * m * m(substring)), where n is length of s and m is the
// length of
// longest word
// space complexity: O(n)