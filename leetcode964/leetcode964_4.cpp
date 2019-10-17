class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        return dp(x, target);
    }
private:
    unordered_map<int, int> memo;
    int dp(int x, int t) {
        if (t == 0) return 0;
        if (t < x) return min(2 * t - 1, 2 * (x - t)); // x = 5, t = 3, (x/x) + (x/x) + (x/x) or x - (x/x) - (x/x)
        if (memo.count(t))
            return memo[t];
        int k = log(t) / log(x);
        long p = pow(x, k);
        if (t == p) 
            return memo[t] = k - 1;
        int ans = dp(x, t - p) + k; // t - p < t
        long left = p * x - t; // left = x ^ (k + 1) - t
        if (left < t) // only rely on smaller sub-problem
            ans = min(ans, dp(x, left) + k + 1);
        return memo[t] = ans;
    }
};


// Runtime: 8 ms, faster than 55.65% of C++ online submissions for Least Operators to Express Number.
// Memory Usage: 12.7 MB, less than 33.33% of C++ online submissions for Least Operators to Express Number.
// time complexity: O(2 * log(t) / log(x))
// space complexity: O(log(t) / log(x))

// Author: Huahua, running time: 8 ms
// class Solution {
// public:
//   int leastOpsExpressTarget(int x, int target) {
//     return dp(x, target);
//   }
// private:
//   unordered_map<int, int> m_;
//   int dp(int x, int t) {
//     if (t == 0) return 0;
//     if (t < x) return min(2 * t - 1, 2 * (x - t));
//     if (m_.count(t)) return m_.at(t);
//     int k = log(t) / log(x);
//     long p = pow(x, k);
//     if (t == p) return m_[t] = k - 1;
//     int ans = dp(x, t - p) + k; // t - p < t
//     long left = p * x - t;
//     if (left < t) // only rely on smaller sub-problems
//       ans = min(ans, dp(x, left) + k + 1);
//     return m_[t] = ans;
//   }
// };
