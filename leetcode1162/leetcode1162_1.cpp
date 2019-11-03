class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, 1, true);
                }
            }
        }
        
        int output = -1;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 1) {
                    output = max(output, grid[i][j] - 1);
                }
            }
        }
        
        return output;
    }
 
    void dfs(vector<vector<int>>& grid, int x, int y, int dist, bool is_land = false) {
        if (!is_land) {
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() 
                || (grid[x][y] != 0 && grid[x][y] <= dist) ) {
                return;
            }
            grid[x][y] = dist;
        }
        
        dist++;
        dfs(grid, x + 1, y, dist);
        dfs(grid, x - 1, y, dist);
        dfs(grid, x, y + 1, dist);
        dfs(grid, x, y - 1, dist);
    }
};
// Runtime: 788 ms, faster than 12.50% of C++ online submissions for As Far from Land as Possible.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for As Far from Land as Possible.
// time complexity: O(m * n * n) m is #of lands
// space complexity: O(n) for the recursion