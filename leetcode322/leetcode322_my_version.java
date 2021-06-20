class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0)
            return 0;

        int[] counts = new int[amount + 1];

        for (int coin : coins) {
            if (coin <= amount) {
                counts[coin] = 1;
            }
        }

        for (int curAmount = 1; curAmount <= amount; curAmount++) {
            if (counts[curAmount] == 0)
                continue;

            for (int coin : coins) {
                // avoid overflow
                // [1,2147483647]
                // 2
                if (curAmount <= amount - coin) {
                    if (counts[curAmount + coin] == 0) {
                        counts[curAmount + coin] = counts[curAmount] + 1;
                    } else {
                        counts[curAmount + coin] = Math.min(counts[curAmount + coin], counts[curAmount] + 1);
                    }
                }
            }
        }

        if (counts[amount] == 0)
            return -1;
        else
            return counts[amount];
    }
}

// Runtime: 19 ms, faster than 47.46% of Java online submissions for Coin
// Change.
// Memory Usage: 38.4 MB, less than 67.55% of Java online submissions for Coin
// Change.
// time complexity: O(amount * coins)
// space complexity: O(amount)
// reference Solution 3