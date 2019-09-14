class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        if (n <= 1) {
            return;
        }
        
        // transpose matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        
        return;
    }
};
// Runtime: 4 ms, faster than 81.62% of C++ online submissions for Rotate Image.
// Memory Usage: 9.1 MB, less than 58.54% of C++ online submissions for Rotate Image.
// time complexity: O(n^2)
// space complexity: O(1)