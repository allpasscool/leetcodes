class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int nx = grid.size(), ny = grid[0].size();
        auto total = grid;
        int walk = 0, min_dist = INT_MIN;
        // cout << "nx: " << nx << "   ny: " << ny << endl;
        
        for (int i = 0; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                // cout << i << ", " << j << endl;
                // find building
                if (grid[i][j] == 1) {
                    // cout << "enter" << endl;
                    min_dist = -1;
                    
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        
                        int x = p.first, y = p.second;
                        
                        // up
                        // cout << "up: " << x << ", " << (y + 1) << endl;
                        if (y + 1 < ny && grid[x][y + 1] == walk) {
                            // cout << "enter" << endl;
                            grid[x][y + 1]--;
                            dist[x][y + 1] = dist[x][y] + 1;
                            total[x][y + 1] += dist[x][y + 1] - 1;
                            q.emplace(x, y + 1);
                            
                            if (min_dist < 0 || min_dist > total[x][y + 1])
                                min_dist = total[x][y + 1];
                        }
                            
                        // down
                        // cout << "down: "<< x << ", " << (y - 1) << endl;
                        if (y - 1 >= 0 && grid[x][y - 1] == walk) {
                            // cout << "enter" << endl;
                            grid[x][y - 1]--;
                            dist[x][y - 1] = dist[x][y] + 1;
                            total[x][y - 1] += dist[x][y - 1] - 1;
                            q.emplace(x, y - 1);
                            
                            if (min_dist < 0 || min_dist > total[x][y - 1])
                                min_dist = total[x][y - 1];
                        }
                        
                        // left
                        // cout << "left:" << (x - 1) << ", " << y << endl;
                        if (x - 1 >= 0 && grid[x - 1][y] == walk) {
                            // cout << "enter" << endl;
                            grid[x - 1][y]--;
                            dist[x - 1][y] = dist[x][y] + 1;
                            total[x - 1][y] += dist[x - 1][y] - 1;
                            q.emplace(x - 1, y);
                            
                            if (min_dist < 0 || min_dist > total[x - 1][y])
                                min_dist = total[x - 1][y];
                        }
                        
                        // right
                        // cout << "right: " << (x + 1) << ", " << y << endl;
                        if (x + 1 < nx && grid[x + 1][y] == walk) {
                            // cout << "enter" << endl;
                            grid[x + 1][y]--;
                            dist[x + 1][y] = dist[x][y] + 1;
                            total[x + 1][y] += dist[x + 1][y] - 1;
                            q.emplace(x + 1, y);
                            
                            if (min_dist < 0 || min_dist > total[x + 1][y])
                                min_dist = total[x + 1][y];
                        }
                    }
                    walk--;
                }
            }
        }
        
        // cout << "finish";
        
        return min_dist;
    }
};
// class Solution {
// public:
// int shortestDistance(vector<vector<int>> grid) {
//     int m = grid.size(), n = grid[0].size();
//     auto total = grid;
//     int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
//     for (int i=0; i<m; ++i) {
//         for (int j=0; j<n; ++j) {
//             if (grid[i][j] == 1) {
//                 mindist = -1;
//                 auto dist = grid;
//                 queue<pair<int, int>> q;
//                 q.emplace(i, j);
//                 while (q.size()) {
//                     auto ij = q.front();
//                     q.pop();
//                     for (int d=0; d<4; ++d) {
//                         int i = ij.first + delta[d];
//                         int j = ij.second + delta[d+1];
//                         if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
//                             grid[i][j]--;
//                             dist[i][j] = dist[ij.first][ij.second] + 1;
//                             total[i][j] += dist[i][j] - 1;
//                             q.emplace(i, j);
//                             if (mindist < 0 || mindist > total[i][j])
//                                 mindist = total[i][j];
//                         }
//                     }
//                 }
//                 walk--;
//             }
//         }
//     }
//     return mindist;
// }
// };

// Runtime: 24 ms, faster than 77.21% of C++ online submissions for Shortest Distance from All Buildings.
// Memory Usage: 26.2 MB, less than 42.86% of C++ online submissions for Shortest Distance from All Buildings.
// time complexity: O((nx * ny) ^ (nx * ny))
// space complexity: O()