class Solution {
public:
    int mySqrt(int x) {
        for (long long i = 1;; ++i) {
            if (i * i == x)
                return i;
            else if (i * i > x) {
                return i - 1;
            }
        }
        
        return -1;
    }
};


// Runtime: 16 ms, faster than 16.17% of C++ online submissions for Sqrt(x).
// Memory Usage: 8.2 MB, less than 98.25% of C++ online submissions for Sqrt(x).
// time complexity: O(x)
// space complexity: O(1)
