class Solution {
    public int fib(int n) {
        if (n == 1)
            return 1;
        else if (n == 0)
            return 0;
        else
            return fib(n - 1) + fib(n - 2);
    }
}

// Runtime: 7 ms, faster than 25.67% of Java online submissions for Fibonacci Number.
// Memory Usage: 36.1 MB, less than 13.97% of Java online submissions for Fibonacci Number.
// time complexity: O(2^n)
// space complexity: O(n)