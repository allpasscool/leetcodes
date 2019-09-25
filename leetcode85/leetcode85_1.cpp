class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ny = matrix.size();
        if (ny == 0)
            return 0;
        
        int nx = matrix[0].size();
        int max_area = 0;
        vector<vector<int>> dp(ny, vector<int> (nx, 0));
        
        // traverse rows
        for (int i = 0; i < ny; ++i) {
            // traverse each column
            for (int j = 0; j < nx; ++j) {
                if (matrix[i][j] == '1') {
                    
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    
                    int width = dp[i][j];
                    
                    //compute the maximum area rectangle with a lower right corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        max_area = max(max_area, width * (i - k + 1));
                    }
                }
            }
        }
        
        return max_area;
    }
};

// Runtime: 80 ms, faster than 5.66% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 11 MB, less than 61.11% of C++ online submissions for Maximal Rectangle.
// time complexity: O(N^2 * M), computing maximum area of one point takes O(N) and there are N * M points
// space complexity: O(NM)
