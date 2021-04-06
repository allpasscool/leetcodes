class Solution {
    public int fib(int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        map.put(1, 1);
        
        for (int i = 2; i <= n; ++i) {
            map.put(i, map.get(i-1) + map.get(i-2));
        }
        
        return map.get(n);
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Fibonacci Number.
// Memory Usage: 35.4 MB, less than 88.03% of Java online submissions for Fibonacci Number.
// time complexity: O(n)
// space complexity: O(n)