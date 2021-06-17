class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < strs[0].length(); i++) {
            char cur = strs[0].charAt(i);

            for (String str : strs) {
                if (i >= str.length() || str.charAt(i) != cur) {
                    return ans.toString();
                }
            }

            ans.append(cur);
        }
        return ans.toString();
    }
}

// Runtime: 1 ms, faster than 62.33% of Java online submissions for Longest
// Common Prefix.
// Memory Usage: 36.7 MB, less than 91.51% of Java online submissions for
// Longest Common Prefix.
// time complexity: O(n * m) n is strs.length(), m is longest prefix
// space complexity: O(m)