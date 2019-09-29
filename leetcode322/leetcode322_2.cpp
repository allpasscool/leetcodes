class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_count = amount + 1;
        vector<int> dp(amount + 1, max_count);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Runtime: 52 ms, faster than 54.86% of C++ online submissions for Coin Change.
// Memory Usage: 12.6 MB, less than 86.27% of C++ online submissions for Coin Change.
// time complexity: O(S * n) S is amount, n is # of coins
// space complexity: O(S)