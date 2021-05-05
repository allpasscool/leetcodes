class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    private void dfs(char[][] grid, int y_start, int x_start) {
        int m = grid.length, n = grid[0].length;
        Stack<int[]> st = new Stack<>();
        st.push(new int[]{y_start, x_start});
        // set to 0
        grid[y_start][x_start] = '0';
        
        while (!st.isEmpty()) {
            int[] pos = st.pop();
            int y = pos[0], x = pos[1];
            
            // up
            if (y > 0 && grid[y-1][x] == '1') {
                st.push(new int[]{y-1, x});
                grid[y-1][x] = '0';
            }
            // down
            if (y < m - 1 && grid[y+1][x] == '1') {
                st.push(new int[]{y+1, x});
                grid[y+1][x] = '0';
            }
            // left
            if (x > 0 && grid[y][x-1] == '1') {
                st.push(new int[]{y, x-1});
                grid[y][x-1] = '0';
            }
            // right
            if (x < n - 1 && grid[y][x+1] == '1') {
                st.push(new int[]{y, x+1});
                grid[y][x+1] = '0';
            }
        }
    }
}

// Runtime: 2 ms, faster than 44.68% of Java online submissions for Number of Islands.
// Memory Usage: 41.6 MB, less than 29.34% of Java online submissions for Number of Islands.
// time complexity: O(m * n)
// space complexity: O(m * n)