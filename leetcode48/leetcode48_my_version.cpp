class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        if (n <= 1) {
            return;
        }
        
        vector<vector<int>> copy_matrix = matrix;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = copy_matrix[n - 1 - j][i];
            }
        }
        return;
    }
};
// Runtime: 4 ms, faster than 81.62% of C++ online submissions for Rotate Image.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Rotate Image.
// time complexity: O(n^2)
// space complexity: O(n^2)