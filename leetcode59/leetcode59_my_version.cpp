class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int row = 0, col = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        // int diry = dir[direction][0], dirx = dir[direction][1];
        // int diry = 0, dirx = 0;
        int count = 1;
        
        while (count <= n * n) {
            if (matrix[row][col] == 0) {
                matrix[row][col] = count;
                ++count;
            }
            
            // change direction?
            // first time visited and not out of bound
            // no need to change direction
            if (row + dir[direction][0] < n && col + dir[direction][1] < n
                && row + dir[direction][0] >= 0 && col + dir[direction][1] >= 0
               && matrix[row + dir[direction][0]][col + dir[direction][1]] == 0) {
                row += dir[direction][0];
                col += dir[direction][1];
            }
            // change direction
            else {
                ++direction;
                direction %= 4;
            }
        }
        
        return matrix;
    }
};

// Runtime: 4 ms, faster than 72.65% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 9 MB, less than 37.50% of C++ online submissions for Spiral Matrix II.
// time complexity: O(n)
// space complexity: O(1)