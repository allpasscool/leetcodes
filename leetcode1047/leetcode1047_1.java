class Solution {
    public String removeDuplicates(String S) {
        StringBuilder ans = new StringBuilder();

        for (Character c : S.toCharArray()) {
            if (ans.length() == 0 || ans.charAt(ans.length() - 1) != c) {
                ans.append(c);
            } else if (ans.charAt(ans.length() - 1) == c) {
                ans.deleteCharAt(ans.length() - 1);
            }
        }

        return ans.toString();
    }
}

// Runtime: 15 ms, faster than 62.37% of Java online submissions for Remove All
// Adjacent Duplicates In String.
// Memory Usage: 39.7 MB, less than 38.30% of Java online submissions for Remove
// All Adjacent Duplicates In String.
// time complexity: O(n)
// space complexity: O(n)