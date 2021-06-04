class Solution {
    private double fastPow(double x, long N) {
        if (N == 0) {
            return 1.0;
        }
        double current_product = fastPow(x, N / 2);
        if (N % 2 == 0) {
            return current_product * current_product;
        } else {
            return current_product * current_product * x;
        }
    }

    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
};

// Runtime: 1 ms, faster than 26.74% of Java online submissions for Pow(x, n).
// Memory Usage: 39.4 MB, less than 5.50% of Java online submissions for Pow(x,
// n).
// time complexity: O(log n)
// space complexity: O(log n)