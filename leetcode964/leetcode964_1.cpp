class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        this->x = x;
        
        return dp(0, target) - 1;
    }
private:
    unordered_map<string, int> memo;
    int x;
    
    int dp(int i, int target) {
        string code = to_string(i) + "#" + to_string(target);
        if (memo.find(code) != memo.end())
            return memo[code];
        
        int ans;
        if (target == 0) {
            ans = 0;
        }
        else if (target == 1) {
            ans = cost(i);
        }
        // when x^39 or more, we think this won't be an optimal solution
        else if (i >= 39) {
            ans = target + 1;
        }
        else {
            int t = target / x;
            int r = target % x;
            ans = min(r * cost(i) + dp(i + 1, t),
                     (x - r) * cost(i) + dp(i + 1, t + 1));
        }
        
        memo[code] = ans;
        return ans;
    }
    
    int cost(int x) {
        return x > 0 ? x : 2;
    }
};

// Runtime: 8 ms, faster than 55.65% of C++ online submissions for Least Operators to Express Number.
// Memory Usage: 10.4 MB, less than 33.33% of C++ online submissions for Least Operators to Express Number.
// time complexity: O(logx (target))
// space complexity: O(log target)