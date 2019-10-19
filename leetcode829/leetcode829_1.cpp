class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        
        for (int k = 2; k < sqrt(2 * N); ++k) {
            if ((N - (k * (k - 1) / 2)) % k == 0) {
                ++count;
            }
        }
        
        return count;
    }
};


// Runtime: 8 ms, faster than 22.38% of C++ online submissions for Consecutive Numbers Sum.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Consecutive Numbers Sum.
// time complexity: O(sqrt(N))
// space complexity: O(1)

// 2 * N = k (2 * x + k + 1), x >= 0, k >= 1,N = (x + 1) + ... + (x + k)
// x + (x+1) + (x+2)+...+ k terms = N
// kx + k*(k-1)/2 = N implies
// kx = N - k*(k-1)/2
// N - k*(k-1)/2 > 0 which implies
// k*(k-1) < 2N which can be approximated to
// k*k < 2N ==> k < sqrt(2N)
// Hence the overall complexity of the algorithm is O(sqrt(N))
// https://leetcode.com/problems/consecutive-numbers-sum/discuss/129015/5-lines-C%2B%2B-solution-with-detailed-mathematical-explanation.
