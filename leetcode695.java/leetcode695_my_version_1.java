class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int max_size = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // find land
                if (grid[i][j] == 1) {
                    int area_of_land = bfs(grid, i, j);                    
                    max_size = Math.max(max_size, area_of_land);
                }
            }
        }
        
        return max_size;
    }
    
    private int bfs(int[][] grid, int i, int j) {
        int m = grid.length, n = grid[0].length;
        int[] dirs = {1, 0, -1, 0};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i,j});
        int area_of_land = 1;
        grid[i][j] = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int y = cur[0], x = cur[1];

            for (int k = 0; k < dirs.length; k++) {
                int newX = x + dirs[k % dirs.length];
                int newY = y + dirs[(k + 1) % dirs.length];

                if (newX >= 0 && newX < n
                   && newY >= 0 && newY < m
                   && grid[newY][newX] == 1) {
                    q.add(new int[]{newY, newX});
                    area_of_land++;
                    grid[newY][newX] = 0;
                }
            }
        }
        
        return area_of_land;
    }
}
// Runtime: 4 ms, faster than 22.98% of Java online submissions for Max Area of Island.
// Memory Usage: 39.4 MB, less than 61.76% of Java online submissions for Max Area of Island.
// time complexity: O(m * n)
// space complexity: O(m * n)