class Solution {
    public int bitwiseComplement(int n) {
        // special case
        if (n == 0)
            return 1;
        
        StringBuilder reversedBinary = new StringBuilder();
        
        // n = 4 => 100
        // reversedBinary = 001
        while (n > 0)
        {
            reversedBinary.append(String.valueOf(n % 2));
            n /= 2;
        }
        
        int len = reversedBinary.length();
        int ans = 0;
        int base = 1;
        
        for (int i = 0; i < len; i++)
        {
            ans += (Integer.valueOf(reversedBinary.charAt(i))  % 2 == 0) ? 1 * base : 0;
            base *= 2;
        }
        
        return ans;
    }
}
// Runtime: 3 ms, faster than 15.99% of Java online submissions for Complement of Base 10 Integer.
// Memory Usage: 38.3 MB, less than 6.78% of Java online submissions for Complement of Base 10 Integer.
// time complexity: O(log n)
// space complexity: O(log n)