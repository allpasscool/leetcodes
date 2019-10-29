class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp[i][j][k] round i, number is j, continuous number is k
        // 1 <= n <= 5000
        // 1 <= j <= 6
        // 1 <= k <= 15
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (6, vector<int> (16, 0)));
        long long ans = 0;
        int mod = 1e9 + 7;
        
        // base case, first round is all one;
        for (int i = 0; i < 6; ++i)
            dp[1][i][1] = 1;
        
        // ith round
        for (int i = 2; i <= n; ++i) {
            // cout << i << endl;
            // number is 
            for (int j = 0; j < 6; ++j) {
                // last number in (i - 1)th round
                for (int k = 0; k < 6; ++k) {
                    // last number continuos times , 1 to rollMax[k]
                    for (int n = 1; n <= rollMax[k]; ++n) {
                        // cout << j << ", " << k << ", " << n << endl;
                        if (j == k && n < rollMax[j]) {
                            dp[i][j][n + 1] = (dp[i][j][n + 1] + dp[i - 1][k][n]) % mod;
                        }
                        else if (j != k){
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][n]) % mod;
                        }
                    }
                }
            }
        }
        
        // cout << "ok";
        
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j <= rollMax[i]; ++j) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        
        return ans;
    }
};


// Runtime: 104 ms, faster than 29.97% of C++ online submissions for Dice Roll Simulation.
// Memory Usage: 31.9 MB, less than 100.00% of C++ online submissions for Dice Roll Simulation.
// time complexity: O(n * 6 * 6 * 15)
// space complexity: O(n * 6 * 15)
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1223-dice-roll-simulation/


// Author: Huahua
// class Solution {
// public:
//   int dieSimulator(int n, vector<int>& rollMax) {
//     constexpr int kMaxRolls = 15;
//     constexpr int kMod = 1e9 + 7;
    
//     // dp[i][j][k] := # of sequences ends with k consecutive j after i rolls
//     vector<vector<vector<int>>> dp(n + 1, 
//         vector<vector<int>>(6, vector<int>(kMaxRolls + 1))); 
    
//     for (int j = 0; j < 6; ++j)
//       dp[1][j][1] = 1; // 1 step, 1 dice, 1 way
    
//     for (int i = 2; i <= n; ++i)
//       for (int j = 0; j < 6; ++j)
//         for (int p = 0; p < 6; ++p)
//           for (int k = 1; k <= rollMax[p]; ++k)
//             if (p != j) // not the same dice
//               dp[i][j][1] = (dp[i][j][1] + dp[i - 1][p][k]) % kMod;
//             else if (k < rollMax[p]) // same dice, make sure k + 1 <= rollMax
//               dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][p][k]) % kMod;
    
//     int ans = 0;
//     for (int j = 0; j < 6; ++j)
//       for (int k = 1; k <= rollMax[j]; ++k)
//         ans = (ans + dp[n][j][k]) % kMod;
  
//     return ans;
//   }
// };