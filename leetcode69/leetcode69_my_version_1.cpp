class Solution {
public:
    int mySqrt(int x) {
        long long left = 1, right = x;
        
        while (left <= right) {
            if (left == right) {
                if (left * left == x)
                    return left;
                else if (left * left > x)
                    return left - 1;
                else 
                    return left;
            }
            
            long long mid = (left + right) / 2;
            
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                left = mid + 1;
            }
            else {
                right = mid;
            } 
        }
        
        
        return left - 1;
    }
};


// Runtime: 4 ms, faster than 76.16% of C++ online submissions for Sqrt(x).
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Sqrt(x).
// time complextiy: O(log n)
// space complexity: O(1)