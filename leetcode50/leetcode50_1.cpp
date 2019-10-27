class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return fastPow(x, N);
    }
private:
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1.0;
        
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return half * half * x;
        }
    }
};


// Runtime: 4 ms, faster than 59.34% of C++ online submissions for Pow(x, n).
// Memory Usage: 8.3 MB, less than 94.64% of C++ online submissions for Pow(x, n).
// time complexity: O(log n)
// space complexity: O(log n)