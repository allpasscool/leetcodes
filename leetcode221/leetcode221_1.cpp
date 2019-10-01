class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows + 1, vector<int> (cols + 1, 0));
        int max_sq_len = 0;
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    max_sq_len = max(max_sq_len, dp[i][j]);
                }
            }
        }
        
        return max_sq_len * max_sq_len;
    }
};

// Runtime: 20 ms, faster than 77.32% of C++ online submissions for Maximal Square.
// Memory Usage: 11.2 MB, less than 44.44% of C++ online submissions for Maximal Square.
// time complexity: O(n * m)
// space complexity: O(n * m)