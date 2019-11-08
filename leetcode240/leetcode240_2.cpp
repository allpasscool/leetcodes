class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start our "pointer" in the bottom-left
        int row = matrix.size() - 1;
        int col = 0;
        
        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            }
            else if (matrix[row][col] < target) {
                ++col;
            }
            else { // found it
                return true;
            }
        }
        
        return false;
    }
};

// Runtime: 68 ms, faster than 68.72% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.
// time complexity: O(m + n)
// space complexity: O(1)