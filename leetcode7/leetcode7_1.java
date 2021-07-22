// Solution 1
// Runtime: 1 ms, faster than 100.00% of Java online submissions for Reverse Integer.
// Memory Usage: 36.3 MB, less than 36.79% of Java online submissions for Reverse Integer.
// time complexity: O(log n)
// space complexity: O(1)
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
}
