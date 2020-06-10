class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
              
        // matrix has to be at least 3 * 3
        if (heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;
        
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n));
        
        // first row
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(heightMap[0][i], make_pair(0, i)));
            visited[0][i]  = true;
        } 
        // last row
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(heightMap[m - 1][i], make_pair(m - 1, i)));
            visited[m - 1][i]  = true;
        }
        // first column
        for (int i = 1; i < m - 1; ++i) {
            pq.push(make_pair(heightMap[i][0], make_pair(i, 0)));
            visited[i][0]  = true;
        }
        // last column
        for (int i = 1; i < m - 1; ++i) {
            pq.push(make_pair(heightMap[i][n - 1], make_pair(i, n - 1)));
            visited[i][n - 1]  = true;
        }
        
        int ans = 0;
        vector<int> dir = {0, 1, 0, -1, 0};
        int max_height = INT_MIN;
        
        // bfs
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int height = cur.first;
            int row = cur.second.first, col = cur.second.second;
            
            max_height = max(max_height, height);
            
            for (int d = 0; d < 4; ++d) {
                int y = row + dir[d], x = col + dir[d + 1];
                if (y < 0 || y >= m || x < 0 || x >= n || visited[y][x])
                    continue;
                
                int diff = max_height - heightMap[y][x];
                if (diff > 0)
                    ans += diff;
                
                pq.push(make_pair(heightMap[y][x], make_pair(y, x)));
                visited[y][x] = true;
            }
        }
        
        return ans;
    }
};

// Runtime: 108 ms, faster than 43.72% of C++ online submissions for Trapping Rain Water II.
// Memory Usage: 10.1 MB, less than 57.03% of C++ online submissions for Trapping Rain Water II.
// time complexity: O(m * n)
// space complexity: O(m * n)
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89472/Visualization-No-Code
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89476/concise-C%2B%2B-priority_queue-solution

// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size(), n = (m == 0) ? 0 : heightMap[0].size();        
//         if(m < 3 || n < 3) return 0;
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(!(i == 0 || i == m-1 || j == 0 || j == n-1)) continue;
//                 pq.push(make_pair(heightMap[i][j], make_pair(i, j)));
//                 visited[i][j] = 1;
//             }
//         }
//         vector<int> dir = {0, 1, 0, -1, 0};
//         int H = INT_MIN;
//         int res = 0;
//         while(!pq.empty())
//         {
//             auto p = pq.top(); pq.pop();
//             int height = p.first, i = p.second.first, j = p.second.second;
//             H = max(H, height);
//             for (int d = 0; d < 4; d++)
//             {
//                 int x = i + dir[d], y = j + dir[d+1];
//                 if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
//                 visited[x][y] = 1;
//                 int diff = H - heightMap[x][y];
//                 if(diff > 0) res += diff;
//                 pq.push(make_pair(heightMap[x][y], make_pair(x, y)));
//             }
//         }
//         return res;
//     } 
// };