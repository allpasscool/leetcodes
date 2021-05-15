class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int max_size = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // find land
                if (grid[i][j] == 1) {
                    int area_of_land = dfs(grid, i, j);                    
                    max_size = Math.max(max_size, area_of_land);
                }
            }
        }
        
        return max_size;
    }
    
    private int dfs(int[][] grid, int r, int c) {
        int m = grid.length, n = grid[0].length;
        
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            return 0;
        }
        
        int area_of_land = 1;
        grid[r][c] = 0;
        // down
        area_of_land += dfs(grid, r - 1, c);
        // up
        area_of_land += dfs(grid, r + 1, c);
        // left
        area_of_land += dfs(grid, r, c - 1);
        // right
        area_of_land += dfs(grid, r, c + 1);
        
        return area_of_land;
    }
}

// Runtime: 2 ms, faster than 99.43% of Java online submissions for Max Area of Island.
// Memory Usage: 39.6 MB, less than 50.00% of Java online submissions for Max Area of Island.
// time complexity: O(m*n)
// space complexity: O(m * n)