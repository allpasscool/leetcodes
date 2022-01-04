class Solution {
    public int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int todo = N, bit = 1;
        
        while (todo != 0) {
            // flip current bit
            N = N ^ bit;
            // prepare for the next run
            bit = bit << 1;
            todo = todo >> 1;
        }
        
        return N;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Complement of Base 10 Integer.
// Memory Usage: 36 MB, less than 27.04% of Java online submissions for Complement of Base 10 Integer.
// Time Complexity: O(1), since we're doing not more than 32 iterations here.
// Space Complexity: O(1)