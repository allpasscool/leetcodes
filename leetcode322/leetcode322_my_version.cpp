class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 || coins.size() == 0)
            return 0;
        
        vector<int> dp(amount + 1, -1);
        vector<bool> visited(amount + 1, false);
        int min_coin = INT_MAX;
        
        for (auto v: coins) {
            min_coin = min(min_coin, v);
            
            if (v <= amount) {
                dp[v] = 1;
                visited[v] = true;
            }
        }
            
        backtrack(coins, amount, dp, visited, min_coin);
        
        
        return dp[amount];
    }
    
    
    void backtrack(vector<int>& coins, int amount, vector<int>& dp, vector<bool>& visited, int& min_coin) {
        if (amount < min_coin) {
            return;
        }
        else if (visited[amount])
            return;
        
        int n = coins.size();
        visited[amount] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            int v = coins[i];
            
            if (amount - v > 0) {
                backtrack(coins, amount - v, dp, visited, min_coin);
                if (dp[amount] == -1 && dp[amount - v] != -1)
                    dp[amount] = dp[amount - v] + 1;
                else if (dp[amount] != -1 && dp[amount - v] != -1)
                    dp[amount] = min(dp[amount], dp[amount - v] + 1);
            }
        }
        
        return;
    }
};

// Runtime: 132 ms, faster than 10.06% of C++ online submissions for Coin Change.
// Memory Usage: 13.3 MB, less than 31.37% of C++ online submissions for Coin Change.
// time complexity: O(amount * n), n is # of coins
// space complexity: O(amount)