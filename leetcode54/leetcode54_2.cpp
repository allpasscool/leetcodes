class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int ny = matrix.size();
        if (ny == 0) 
            return output;
        int nx = matrix[0].size();
        int row_down = 0, row_up = ny - 1;
        int col_left = 0, col_right = nx - 1;
        output = vector<int> (nx * ny, 0);
        int counter = 0;
        
        while (row_down <= row_up && col_left <= col_right) {
            for (int c = col_left; c <= col_right; ++c) {
                output[counter] = matrix[row_down][c];
                ++counter;
            }
            for (int r = row_down + 1; r <= row_up; ++r) {
                output[counter] = matrix[r][col_right];
                ++counter;
            }
            
            if (row_down < row_up && col_left < col_right) {
                for (int c = col_right - 1; c > col_left; c--) {
                    output[counter] = matrix[row_up][c];
                    ++counter;
                }
                for (int r = row_up; r > row_down; r--) {
                    output[counter] = matrix[r][col_left];
                    ++counter;
                }
            }
            
            ++row_down;
            row_up--;
            ++col_left;
            col_right--;
        }
        
        return output;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Spiral Matrix.
// time complexity: O(nx * ny)
// space complexity: O(1)