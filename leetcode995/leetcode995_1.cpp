class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        // Tell when to close an interval
        vector<bool> need_close(n, false);
        int ans = 0, n_intervals = 0;
        for (int i = 0; i < n; i++) {
            // Close this interval if needed
            if (need_close[i]) {
                n_intervals--;
            }
            // when meet following two situations, we need flipping here
            // if A[i] is 0 and number of intervals is even
            // --> means the flippings are totally cancelled. We need another flip
            // If A[i] is 1 and number of intervals is odd
            // --> means we have 1 before but being flipped to 0. Need flip again.
            if (A[i] == 0 && n_intervals % 2 == 0 
               || A[i] == 1 && n_intervals % 2 == 1) {
                // Need flip again. Update answer count
                ans++;
                // Generate an interval
                n_intervals++;
                if (i > n - K) {
                    // A[n - K] is the final possible flipping position
                    // i > n - K means we need to flip the subarray is less than K elements 
                    // impossible!
                    return -1;
                }
                
                // Update need_close, so the current interval will be colsed at A[i + K]
                if (i + K < n) {
                    need_close[i + K] = true;
                }

                // if i + K == n, that means the last interval will close exactly at the end of A
                // we don't need to mark this or worry about this
            }
        }
        
        return ans;
    }
};
// Runtime: 84 ms, faster than 86.36% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.
// Memory Usage: 15.9 MB, less than 100.00% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.
// time complexity: O(N)
// space complexity: O(N)