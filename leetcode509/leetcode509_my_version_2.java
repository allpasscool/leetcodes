class Solution {
    public int fib(int n) {
        if (n == 1)
            return 1;
        else if (n == 0)
            return 0;
        
        int ans = 0, n1 = 1, n2 = 0;
        
        for (int i = 2; i <= n; ++i) {
            ans = n1 + n2;
            n2 = n1;
            n1 = ans;
        }
        
        return ans;
    }
}


// Runtime: 0 ms, faster than 100.00% of Java online submissions for Fibonacci Number.
// Memory Usage: 35.4 MB, less than 88.03% of Java online submissions for Fibonacci Number.
// time complexity: O(n)
// space complexity: O(1)