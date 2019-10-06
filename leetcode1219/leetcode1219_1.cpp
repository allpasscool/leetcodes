class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int max_G = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    max_G = max(max_G, dfs(grid, i, j));
                }
            }
        }
        
        return max_G;
    }
    
    int dfs (vector<vector<int>>& grid, int y, int x) {
        int max_G = grid[y][x];
        int m = grid.size();
        int n = grid[0].size();
        int tmp = grid[y][x];
        grid[y][x] = 0;
        
        // up
        if (y + 1 < m && grid[y + 1][x] != 0)
            max_G = max(max_G, tmp + dfs(grid, y + 1, x));
        // down
        if (y - 1 >= 0 && grid[y - 1][x] != 0)
            max_G = max(max_G, tmp + dfs(grid, y - 1, x));
        // left
        if (x - 1 >= 0 && grid[y][x - 1] != 0)
            max_G = max(max_G, tmp + dfs(grid, y, x - 1));
        // right
        if (x + 1 < n && grid[y][x + 1] != 0)
            max_G = max(max_G, tmp + dfs(grid, y, x + 1));
        
        grid[y][x] = tmp;
        return max_G;
    }
};

// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Path with Maximum Gold.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Path with Maximum Gold.
// time complexity: O((n * m)!) from each position might visited all position
// space complexity: O(n*m), might call at most n*m deep dfs