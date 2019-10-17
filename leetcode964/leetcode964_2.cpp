class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        set<pair<int, int>> q; // from x -> number, priority queue, <cost, target_remain>, increasing order
        unordered_set<int> seen; // target
        q.emplace(0, target);
        
        while (!q.empty()) {
            const auto it = begin(q);
            const int cost = it->first;
            const int t = it->second;
            q.erase(it);
            if (t == 0) return cost - 1; // the beginning operator needs to be removed, + x * x == x * x
            if (seen.count(t))
                continue;
            seen.insert(t);
            int k = log(t) / log(x); // logx (t) = k;
            int left = t - pow(x, k); // left = target - x^k
            q.emplace(cost + (k == 0 ? 2 : k), left); // cost for x^0 = 2, for x^1 = 1, x^2 = x * x = 2;
            int right = pow(x, k + 1) - t; // right = x^(k + 1) - t;
            q.emplace(cost + k + 1, right);
        }
        
        return -1;
    }
};

// Runtime: 24 ms, faster than 27.68% of C++ online submissions for Least Operators to Express Number.
// Memory Usage: 12.9 MB, less than 33.33% of C++ online submissions for Least Operators to Express Number.
// time complexity: O(nlogn)
// space complexity: O(nlogn)
// n = x * log(t) / log(x)

// class Solution {
// public:
//   int leastOpsExpressTarget(int x, int target) {
//     set<pair<int, int>> q; // # x -> number
//     unordered_set<int> s;
//     q.emplace(0, target);
//     while (!q.empty()) {
//       const auto it = begin(q);
//       const int c = it->first;
//       const int t = it->second;
//       q.erase(it);
//       if (t == 0) return c - 1;
//       if (s.count(t)) continue;
//       s.insert(t);      
//       int n = log(t) / log(x);
//       int l = t - pow(x, n);
//       q.emplace(c + (n == 0 ? 2 : n), l);
//       int r = pow(x, n + 1) - t;
//       q.emplace(c + n + 1, r);
//     }
//     return -1;
//   }
// };
// https://zxi.mytechroad.com/blog/uncategorized/leetcode-964-least-operators-to-express-number/
