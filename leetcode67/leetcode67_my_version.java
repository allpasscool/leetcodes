// Reference leetcode 415 Add Strings

class Solution {
    public String addBinary(String a, String b) {
        if (a.length() < b.length()) {
            String tmp = a;
            a = b;
            b = tmp;
        }

        int n1 = a.length(), n2 = b.length();
        StringBuilder ans = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < n1; i++) {
            int cur = a.charAt(n1 - 1 - i) - '0';

            if (i < n2)
                cur += b.charAt(n2 - 1 - i) - '0';
            cur += carry;
            ans.append(String.valueOf(cur % 2));
            carry = cur / 2;
        }

        if (carry == 1)
            ans.append(1);

        return ans.reverse().toString();
    }
}

// Runtime: 2 ms, faster than 75.66% of Java online submissions for Add Binary.
// Memory Usage: 39.2 MB, less than 23.11% of Java online submissions for Add
// Binary.
// time complexity: O(n)
// space complexity: O(1)