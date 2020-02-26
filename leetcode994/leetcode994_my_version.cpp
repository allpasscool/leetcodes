class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh_count = 0; // fresh
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++fresh_count;
                }
                else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
        
        if (fresh_count == 0)
            return 0;
        
        int elapse = -1;
        
        while (!rotten.empty()) {
            int r_size = rotten.size(); // rotten orange this round
            
            for (int i = 0; i < r_size; ++i) {
                pair<int, int> r = rotten.front();
                rotten.pop();
                // down
                if (r.first > 0 && grid[r.first - 1][r.second] == 1) {
                    grid[r.first -1][r.second] = 2;
                    rotten.push({r.first - 1, r.second});
                }
                // up
                if (r.first < grid.size() - 1 && grid[r.first + 1][r.second] == 1) {
                    grid[r.first + 1][r.second] = 2;
                    rotten.push({r.first + 1, r.second});
                }
                // right
                if (r.second < grid[0].size() - 1 && grid[r.first][r.second + 1] == 1) {
                    grid[r.first][r.second + 1] = 2;
                    rotten.push({r.first, r.second + 1});
                }
                
                // left
                if (r.second > 0 && grid[r.first][r.second - 1] == 1) {
                    grid[r.first][r.second - 1] = 2;
                    rotten.push({r.first, r.second - 1});
                }
            }
            
            fresh_count -= rotten.size();
            ++elapse;
        }
        
        return fresh_count == 0 ? elapse : -1;
    }
};


// Runtime: 4 ms, faster than 95.16% of C++ online submissions for Rotting Oranges.
// Memory Usage: 9.2 MB, less than 62.50% of C++ online submissions for Rotting Oranges.
// time complexity: O(n)
// space complexity: O(n)