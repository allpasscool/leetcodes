class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        int row = m - 1, col = n - 1;
        
        while (row >= 0 && col >= 0) {
            if (grid[row][col] < 0 && col == 0) {
                count += n;
                row--;
            }
            else if (grid[row][col] < 0 && col > 0) {
                col--;
                if (grid[row][col] >= 0) {
                    count += n - col - 1;
                    ++col;
                    row--;
                }
            }
            else if (grid[row][col] >= 0 && col < (n - 1)) {
                ++col;
            }
            else if (grid[row][col] >= 0 && col == (n - 1)) {
                row--;
            }
        }
        
        return count;
    }
};


// Runtime: 16 ms, faster than 88.89% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// time complexity: O(n + m)
// space complexity: O(1)