class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int nx = grid.size();
        if (nx == 0) {
            return -1;
        }
        int ny = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(nx, vector<bool> (ny, false));
        //push all lands into queue
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }
        
        
        int level = -1;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        //bfs
        while (!q.empty()) {
            int this_level = q.size();
            for (int i = 0; i < this_level; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                for (int j = 0; j < 4; j++) {
                    int new_x = x + dir[j][0];
                    int new_y = y + dir[j][1];
                    
                    if (new_x >= 0 && new_x < nx
                       && new_y >= 0 && new_y < ny
                       && !visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        q.push(make_pair(new_x, new_y));
                    }
                }
                
            }
            level++;
        }
        
        return level <= 0 ? -1 : level;
    }
};
// Runtime: 52 ms, faster than 87.50% of C++ online submissions for As Far from Land as Possible.
// Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for As Far from Land as Possible.
// time complexity: O(n)
// space complexity: O(n)