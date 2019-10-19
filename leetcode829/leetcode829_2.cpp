class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        
        for (int k = 1; ; k++) {
            int kx = N - k * (k - 1) / 2;
            if (kx <= 0)
                break;
            if (kx % k == 0)
                ++ans;
        }
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 84.55% of C++ online submissions for Consecutive Numbers Sum.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Consecutive Numbers Sum.
// time complexity: O(sqrt(N))
// space copmlexity: O(1)

// x + (x+1) + (x+2)+...+ k terms = N
// kx + k*(k-1)/2 = N implies
// kx = N - k*(k-1)/2
// https://leetcode.com/problems/consecutive-numbers-sum/discuss/209317/topic
