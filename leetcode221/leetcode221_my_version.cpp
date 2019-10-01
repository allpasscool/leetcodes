class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) 
            return 0;
        int m = matrix[0].size();
        // dp[n][m] means indlcude this, how many consecutive 1s
        vector<vector<int>> dp(n, vector<int> (m, 0)); 
        
        // put consecutive 1s into dp
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    if (j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i][j - 1] + 1;
                }
            }
        }
        
        int max_square = 0;
        
        // find max 1s square
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] > 0) {
                    int max_width = dp[i][j];
                    
                    // from this point, count all above possible
                    for (int k = i; k >= 0 && dp[k][j] > 0; k--) {
                        max_width = min(max_width, dp[k][j]);
                        
                        max_square = max(max_square, 
                                         min(max_width, i - k + 1) * min(max_width, i - k + 1));
                    }
                }
            }
        }
        
        
        return max_square;
    }
};

// Runtime: 40 ms, faster than 10.43% of C++ online submissions for Maximal Square.
// Memory Usage: 11.3 MB, less than 37.04% of C++ online submissions for Maximal Square.
// time complexity: O(n*n*m)
// space complexity: O(n*m)