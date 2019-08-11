class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        int MOD = 1e9 + 7;
        
        //dice
        for (int i = 1; i <= d; i++) {
            //target
            for (int j = target; j >= 0; j--) {
                dp[j] = 0;
                
                if (i * f < j) {
                    continue;
                }
                //last dice's number
                for (int k = 1; k <= f && k <= j; k++) {
                    dp[j] = (dp[j] + dp[j - k]) % MOD;
                }
            }
        }
        
        return dp[target];
    }
};
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Number of Dice Rolls With Target Sum.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Number of Dice Rolls With Target Sum.
// time complexity: O(d * target * f)
// space complexity: O(target + 1)
//ps. backtracking will over times