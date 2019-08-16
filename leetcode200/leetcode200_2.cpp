class Solution {
public:
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
                    grid[r][c] = '0'; // mark as visited
                    
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1') {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1') {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        
        return num_islands;
    }
};
// Runtime: 12 ms, faster than 91.97% of C++ online submissions for Number of Islands.
// Memory Usage: 11.4 MB, less than 25.84% of C++ online submissions for Number of Islands.
// Time complexity : O(M×N) where M is the number of rows and N is the number of columns.
// Space complexity : O(min(M,N)) because in worst case where the grid is filled with lands, the size of queue can grow up to min(M,N).