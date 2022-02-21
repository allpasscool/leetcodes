class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int num = 0;

        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (grid[y][x] == '1' && !visited[y][x])
                {
                    dfs(grid, visited, y, x);
                    num++;
                }
            }
        }

        return num;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int y, int x)
    {
        // out of bound
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size())
            return;
        // not a land or visited before
        if (grid[y][x] == '0' || visited[y][x])
            return;

        visited[y][x] = true;
        dfs(grid, visited, y + 1, x);
        dfs(grid, visited, y - 1, x);
        dfs(grid, visited, y, x + 1);
        dfs(grid, visited, y, x - 1);
    }
};

// Runtime: 48 ms, faster than 54.81% of C++ online submissions for Number of Islands.
// Memory Usage: 12.6 MB, less than 43.57% of C++ online submissions for Number of Islands.
// time complexity: O(m * n)
// space complexity: O(m * n)