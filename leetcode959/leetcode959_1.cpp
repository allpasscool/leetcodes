class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4 * n * n);
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int index = 4 * (r * n + c);
                switch(grid[r][c]) {
                    case '/':
                        dsu.merge(index + 0, index + 3);
                        dsu.merge(index + 1, index + 2);
                        break;
                    case '\\':
                        dsu.merge(index + 0, index + 1);
                        dsu.merge(index + 2, index + 3);
                        break;
                    case ' ':
                        dsu.merge(index + 0, index + 1);
                        dsu.merge(index + 1, index + 2);
                        dsu.merge(index + 2, index + 3);
                        break;
                    default:
                        break;
                }
                if (r + 1 < n) {
                    dsu.merge(index + 2, index + 4 * n + 0);
                }
                if (c + 1 < n) {
                    dsu.merge(index + 1, index + 4 + 3);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (dsu.find(i) == i) {
                ans++;
            }
        }
        return ans;
    }
private:
    class DSU {
        public:
            DSU(int n): parent_(n) {
                for (int i = 0; i < n; i++) {
                    parent_[i] = i;
                }
            }
            
            int find(int x) {
                if (parent_[x] != x) {
                    parent_[x] = find(parent_[x]);
                }
                return parent_[x];
            }
            
            void merge(int x, int y) {
                parent_[find(x)] = find(y);
            }
        private:
            vector<int> parent_;
    };
};
// Runtime: 8 ms, faster than 93.80% of C++ online submissions for Regions Cut By Slashes.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Regions Cut By Slashes.
// time complexity: O(N * N * α(N)), where N is the length of the grid, and α is the Inverse-Ackermann function (if we were to use union-find by rank.)
// space complexity: O( N * N)
// https://zxi.mytechroad.com/blog/graph/leetcode-959-regions-cut-by-slashes/