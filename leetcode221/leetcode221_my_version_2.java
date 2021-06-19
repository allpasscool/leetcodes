class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] squares = new int[n];
        int ans = 0;

        // base case
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == '1') {
                squares[i] = 1;
                ans = Math.max(ans, squares[i]);
            }
        }

        // square[i-1][j-1]
        int leftUp;
        // squares[i-1][j]
        int up;
        for (int i = 1; i < m; i++) {
            leftUp = 0;
            up = 0;
            if (matrix[i][0] == '1') {
                leftUp = squares[0];
                squares[0] = 1;
                ans = Math.max(ans, squares[0]);
            } else {
                squares[0] = 0;
            }

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    up = squares[j];
                    squares[j] = Math.min(leftUp, Math.min(squares[j], squares[j - 1])) + 1;
                    ans = Math.max(ans, squares[j]);
                    leftUp = up;
                } else {
                    squares[j] = 0;
                }
            }
        }

        return ans * ans;
    }
}

// Runtime: 3 ms, faster than 98.47% of Java online submissions for Maximal
// Square.
// Memory Usage: 42.9 MB, less than 18.37% of Java online submissions for
// Maximal Square.
// time complexity: O(m * n)
// space complexity: O(n)