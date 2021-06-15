class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> st = new Stack<>();

        for (Character c : S.toCharArray()) {
            if (st.isEmpty() || st.peek() != c) {
                st.push(c);
            } else if (st.peek() == c) {
                st.pop();
            }
        }

        StringBuilder ans = new StringBuilder();

        while (!st.isEmpty()) {
            ans.insert(0, st.pop());
        }

        return ans.toString();
    }
}

// Runtime: 51 ms, faster than 25.13% of Java online submissions for Remove All
// Adjacent Duplicates In String.
// Memory Usage: 39.9 MB, less than 29.58% of Java online submissions for Remove
// All Adjacent Duplicates In String.
// time complexity: O(n)
// space complexity: O(n)