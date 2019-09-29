class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;
        
        vector<int> count(amount, 0);
        
        return topDown(coins, amount, count);
    }
    
    int topDown(vector<int>& coins, int rem, vector<int>& count) {
        if (rem < 0)
            return -1;
        else if (rem == 0)
            return 0;
        else if (count[rem - 1] != 0)
            return count[rem - 1];
        
        int min_count = INT_MAX;
        
        for (auto coin: coins) {
            int result = topDown(coins, rem - coin, count);
            if (result >= 0 && result < min_count)
                min_count = result + 1;
        }
        
        count[rem - 1] = (min_count == INT_MAX) ? -1 : min_count;
        return count[rem - 1];
    }
};

// Runtime: 76 ms, faster than 19.11% of C++ online submissions for Coin Change.
// Memory Usage: 13.9 MB, less than 31.37% of C++ online submissions for Coin Change.
// time complexity: O(S * n), S is the amount, n is # of coins
// space complexity: O(S)