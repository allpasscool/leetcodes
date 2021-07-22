// Runtime: 1 ms, faster than 100.00% of Java online submissions for Reverse Integer.
// Memory Usage: 36.5 MB, less than 30.99% of Java online submissions for Reverse Integer.
// time complexity: O(log n)
// space complexity: O(1)

class Solution {
    public int reverse(int x) {
        boolean sign = x >= 0;
        long ans = 0;
        
        if (x < 0)
            x *= -1;
        
        while (x != 0)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        
        if (!sign)
            ans *= -1;
        
        // outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
        if (ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE)
            return 0;
        
        return (int)ans;
    }
}

