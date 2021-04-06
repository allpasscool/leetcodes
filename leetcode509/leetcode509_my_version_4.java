class Solution {
    public int fib(int n) {
        int[] arr = new int[n+1];
        arr[0] = 0;
        
        if (n < 1)
            return arr[n];
        
        arr[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        
        return arr[n];
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Fibonacci Number.
// Memory Usage: 35.8 MB, less than 44.13% of Java online submissions for Fibonacci Number.
// time complexity: O(n)
// space complexity: O(n)