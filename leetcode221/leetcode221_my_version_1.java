class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] squares = new int[m][n];
        int ans = 0;

        // base case
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                squares[i][0] = 1;
                ans = Math.max(ans, squares[i][0]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == '1') {
                squares[0][i] = 1;
                ans = Math.max(ans, squares[0][i]);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    squares[i][j] = Math.min(squares[i - 1][j - 1], Math.min(squares[i - 1][j], squares[i][j - 1])) + 1;
                    ans = Math.max(ans, squares[i][j]);
                }
            }
        }

        return ans * ans;
    }
}

// Runtime: 4 ms, faster than 91.31% of Java online submissions for Maximal
// Square.
// Memory Usage: 42.6 MB, less than 24.76% of Java online submissions for
// Maximal Square.
// time complexity: O(m * n)
// space complexity: O(m * n)