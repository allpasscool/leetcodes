class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        
        queue<pair<int, int>> next;
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (columns, false));
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (visited[i][j] || grid[i][j] == '0') {
                    continue;
                }
                count++;
                next.push(make_pair(i, j));
                
                while (!next.empty()) {
                    pair<int, int> next_point = next.front();
                    next.pop();
                    int r = next_point.first, c = next_point.second;
                    if (!visited[r][c]) {
                        visited[r][c] = true;
                    }
                    else {
                        continue;
                    }
                    
                    //down
                    if (r + 1 < rows && grid[r + 1][c] == '1') {
                        next.push(make_pair(r + 1, c));
                    }
                    //right
                    if (c + 1 < columns && grid[r][c + 1] == '1') {
                        next.push(make_pair(r, c + 1));
                    }
                    //left
                    if (c - 1 >= 0 && grid[r][c - 1] == '1' && !visited[r][c - 1]) {
                        next.push(make_pair(r, c - 1));
                    }
                    //up
                    if (r - 1 >= 0 && grid[r - 1][c] == '1' && !visited[r - 1][c]) {
                        next.push(make_pair(r - 1, c));
                    }
                }
            }
        }
        
        return count;
    }
};
// Runtime: 16 ms, faster than 60.33% of C++ online submissions for Number of Islands.
// Memory Usage: 11.1 MB, less than 38.20% of C++ online submissions for Number of Islands.
// time complexity: O(n)
// space complexity: O(n)