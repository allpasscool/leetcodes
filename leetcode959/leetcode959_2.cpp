class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int n = grid.size();
        vector<vector<int>> g(n * 3, vector<int> (n * 3)); // one char become 3 * 3 pixels
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    g[i * 3 + 0][j * 3 + 2] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3 + 0] = 1;
                }
                else if (grid[i][j] == '\\') {
                    g[i * 3 + 0][j * 3 + 0] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (g[i][j] == 1) {
                    continue;
                }
                visit(g, i, j, n * 3);
                ans++;
            }
        }
        return ans;
    }
    
private:
    void visit(vector<vector<int>>& g, int x, int y, int n) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return;
        }
        
        if (g[x][y] == 1) {
            return;
        }
        g[x][y] = 1;
        visit(g, x + 1, y, n);
        visit(g, x - 1, y, n);
        visit(g, x, y + 1, n);
        visit(g, x, y - 1, n);
    }
};
// Runtime: 8 ms, faster than 93.80% of C++ online submissions for Regions Cut By Slashes.
// Memory Usage: 11 MB, less than 25.00% of C++ online submissions for Regions Cut By Slashes.
// time complexity: O(n^2)
// space complexity: O(n^2)