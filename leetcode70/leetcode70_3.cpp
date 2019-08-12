class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        int first = 1, second = 2;
        
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        
        return second;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.2 MB, less than 98.53% of C++ online submissions for Climbing Stairs.
// time complexity: O(n)
// space complexity: O(1)