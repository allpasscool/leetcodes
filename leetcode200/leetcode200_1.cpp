class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        
        grid[r][c] = '0';
        
        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
            dfs(grid, r - 1, c);
        }
        if (r + 1 < nr && grid[r + 1][c] == '1') {
            dfs(grid, r + 1, c);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
            dfs(grid, r, c - 1);
        }
        if (c + 1 < nc && grid[r][c + 1] == '1') {
            dfs(grid, r, c + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0) {
            return 0;
        }
        
        int nc = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(grid, r, c);
                }
            }
        }
        
        return num_islands;
    }
};
// Runtime: 8 ms, faster than 99.23% of C++ online submissions for Number of Islands.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Number of Islands.
// time complexity: O(m * n), m is rows, n is columns
// space complexity: O(m * n)  in case that the grid map is filled with lands where DFS goes by m * n deep.