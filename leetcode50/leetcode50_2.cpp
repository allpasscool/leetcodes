class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        
        if (N < 0) {
            x  = 1 / x;
            N = -N;
        }
        
        double ans = 1;
        double current_product = x;
        
        for (long long i = N; i != 0; i /= 2) {
            if (i % 2 == 1) {
                ans *= current_product;
            }
            
            current_product *= current_product;
        }
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 59.34% of C++ online submissions for Pow(x, n).
// Memory Usage: 8.5 MB, less than 28.57% of C++ online submissions for Pow(x, n).
// time complexity: O(log n)
// space complexity: O(log n)