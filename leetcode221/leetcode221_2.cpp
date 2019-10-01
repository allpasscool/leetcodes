class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        // vector<vector<int>> dp(rows + 1, vector<int> (cols + 1, 0));
        vector<int> dp(cols + 1, 0);
        int max_sq_len = 0, prev = 0; // prev is dp[cur_row - 1][cur_col - 1]
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    // dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    max_sq_len = max(max_sq_len, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                
                prev = tmp;
            }
        }
        
        return max_sq_len * max_sq_len;
    }
};

// Runtime: 16 ms, faster than 96.39% of C++ online submissions for Maximal Square.
// Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Maximal Square.
// time complexity: O(n *m) 
// space complexity: O(m)