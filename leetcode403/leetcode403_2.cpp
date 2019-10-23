
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        for (int pos : stones) {
            for (int step : dp[pos]) {
                if (step-1 > 0) dp[pos + step-1].insert(step-1);
                dp[pos + step].insert(step);
                dp[pos + step+1].insert(step+1);
            }
        }
        return !dp[stones.back()].empty();
    }
};

// Runtime: 140 ms, faster than 57.89% of C++ online submissions for Frog Jump.
// Memory Usage: 44.3 MB, less than 10.00% of C++ online submissions for Frog Jump.
// time complexity: O(n^2)
// space complexity: O(n^2)