class Solution {
    public int bitwiseComplement(int N) {
        
        // l is a length of N in binary representation
        int l = (int)( Math.log(N) / Math.log(2) ) + 1;
        
        // bitmask has the same length as num and contains only ones 1...1
        int bitmask = (1 << l) - 1;
        
        // flip all bits
        return bitmask ^ N;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Complement of Base 10 Integer.
// Memory Usage: 37.7 MB, less than 9.94% of Java online submissions for Complement of Base 10 Integer.
// Time complexity: O(1)
// Space complexity: O(1)