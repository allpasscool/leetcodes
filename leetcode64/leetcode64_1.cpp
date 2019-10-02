class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        // vector<int> dp(n, INT_MAX);
        // dp[0] = grid[0][0];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && j != 0)
                    grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
                else if (i == 0 && j != 0)
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                else if (i != 0 && j == 0)
                    grid[i][j] = grid[i][j] + grid[i - 1][j];   
            }
        }
        
        return grid[m - 1][n - 1];
    }
};

// Runtime: 12 ms, faster than 45.52% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Minimum Path Sum.
// time complexity: O(mn)
// space complexity: O(1)