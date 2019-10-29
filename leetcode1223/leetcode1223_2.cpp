class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        const int mod = 1e9 + 7;
        // dp[i][j] := # of subsequence ends with j after i rolls
        vector<vector<int>> dp(n + 1, vector<int> (7));
        vector<int> sums(n + 1); // sums[i] := sum(dp[i])
        
        // base case, 1 roll 1 dice 1 way
        for (int i = 0; i < 6; ++i) {
            dp[1][i] = 1;
            sums[1] += dp[1][i];
        }
        
        // round i
        for (int i = 2; i <= n; ++i) {
            // last round ends with dice j
            for (int j = 0; j < 6; ++j) {
                // for example, i = 8, k = 5, rollMax[5] = 3
                // k > 1 means there are some invalid from i - 1 rounds
                // therefore, we need to eliminate some invalid cases
                // the only invalid will be dp[k - 1][j]
                // xxxxxxx|6
                // xxxxx66|6 ok
                // xxxx666|6 invalid
                // invalid will be sums[4] - dp[4][5];
                // because it will never possible be
                // xxx6666|6 is already be invalid before come to round 8
                // the only possible is at round 4 is not 6 and round 5, 6, 7 is all 6
                // therefore, invalid is sums[k - 1] - dp[k - 1][j]
                // dp[i][j] = sums[i - 1] - invalid
                // k <= 1 means no invalid or only one possible, which is all j 
                const int k = i - rollMax[j];
                const int invalid = k <= 1 ? max(k, 0) : sums[k - 1] - dp[k - 1][j];
                // ((sums[i - 1] - invalid) % mod + mod) % mod
                // because after mod, sums[i - 1] might < invalid
                dp[i][j] = ((sums[i - 1] - invalid) % mod + mod) % mod;
                sums[i] = (sums[i] + dp[i][j]) % mod;
            }
            
        }
        
        return sums[n];
            
    }
};


// Runtime: 8 ms, faster than 97.44% of C++ online submissions for Dice Roll Simulation.
// Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Dice Roll Simulation.
// time complexity: O(n * 6)
// space complexity: O(n * 6)
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1223-dice-roll-simulation/

// Author: Huahua
// class Solution {
// public:
//   int dieSimulator(int n, vector<int>& rollMax) {
//     constexpr int kMod = 1e9 + 7;    
//     // dp[i][j] := # of sequences ends with j after i rolls    
//     vector<vector<int>> dp(n + 1, vector<int>(7));    
//     vector<int> sums(n + 1); // sums[i] := sum(dp[i])
    
//     for (int j = 0; j < 6; ++j)
//       sums[1] += dp[1][j] = 1; // 1 roll, 1 dice, 1 way
    
//     for (int i = 2; i <= n; ++i)
//       for (int j = 0; j < 6; ++j) {        
//         const int k = i - rollMax[j];
//         const int invalid = k <= 1 ? max(k, 0) : sums[k - 1] - dp[k - 1][j];
//         dp[i][j] = ((sums[i - 1] - invalid) % kMod + kMod) % kMod;
//         sums[i] = (sums[i] + dp[i][j]) % kMod;
//       }
  
//     return sums[n];
//   }
// };