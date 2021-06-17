class Solution {
    public String addStrings(String num1, String num2) {
        if (num1.length() < num2.length()) {
            String tmp = num1;
            num1 = num2;
            num2 = tmp;
        }

        int n1 = num1.length(), n2 = num2.length();
        StringBuilder ans = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < n1; i++) {
            int cur = num1.charAt(n1 - 1 - i) - '0';

            if (i < n2)
                cur += num2.charAt(n2 - 1 - i) - '0';
            cur += carry;
            ans.append(String.valueOf(cur % 10));
            carry = cur / 10;
        }

        if (carry == 1)
            ans.append(1);

        return ans.reverse().toString();

    }
}

// Runtime: 2 ms, faster than 92.31% of Java online submissions for Add Strings.
// Memory Usage: 38.7 MB, less than 92.32% of Java online submissions for Add
// Strings.
// time complexity: O(n)
// space complexity: O(1)