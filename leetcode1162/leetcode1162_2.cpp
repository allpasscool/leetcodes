class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int nx = grid.size();
        if (nx == 0) {
            return -1;
        }
        int ny = grid[0].size();
        
        queue<pair<int, int>> q;
        //push all lands into queue
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        
        vector<vector<bool>> visited(nx, vector<bool> (ny, false));
        int level = -1;
        
        //bfs
        while (!q.empty()) {
            int this_level = q.size();
            for (int i = 0; i < this_level; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                if (x < 0 || y < 0 || x >= nx || y >= ny 
                   || visited[x][y]) {
                    continue;
                }
                
                visited[x][y] = true;
                if (x + 1 < nx && grid[x + 1][y] == 0) { 
                    q.push(make_pair(x + 1, y));
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 0) {
                    q.push(make_pair(x - 1, y));
                }
                if (y + 1 < ny && grid[x][y + 1] == 0) {
                    q.push(make_pair(x, y + 1));
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 0) {
                    q.push(make_pair(x, y - 1));
                }
                
            }
            level++;
        }
        
        return level <= 0 ? -1 : level - 1;
    }
};
// Runtime: 72 ms, faster than 12.50% of C++ online submissions for As Far from Land as Possible.
// Memory Usage: 19.2 MB, less than 100.00% of C++ online submissions for As Far from Land as Possible.
// time complexity: O(m * n * n)
// space complexity: O(n * n)