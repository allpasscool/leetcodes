class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = grid[0][0];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // from up
                if (i > 0) {
                    dp[j] = dp[j] + grid[i][j];
                }
                // from left
                if (j > 0) {
                    dp[j] = min(dp[j - 1] + grid[i][j], dp[j]);
                }
            }
        }
        
        return dp[n - 1];
    }
};

// Runtime: 12 ms, faster than 45.52% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Minimum Path Sum.
// time complexity: O(mn)
// space complexity: O(n)