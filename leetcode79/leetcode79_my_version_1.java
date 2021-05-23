class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        
        // rows
        for (int i = 0; i < m; i++) 
        {
            // cols
            for (int j = 0; j < n; j++) 
            {
                // if this pos match the first letter in word
                if (board[i][j] == word.charAt(0))
                {
                    // find word
                    if (dfs(board, word, i, j, visited, 0) == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int y, int x, boolean[][] visited, int pos) {
        // find all letters
        if (pos == word.length())
            return true;
        
        // out of bound
        if (y < 0 || x < 0 || y >= board.length || x >= board[0].length)
            return false;
        
        if (visited[y][x] == false && board[y][x] == word.charAt(pos))
        {
            // this step
            visited[y][x] = true;
            // next stpe, visit up, down, left, right
            if (dfs(board, word, y+1, x, visited, pos + 1) == true
                || dfs(board, word, y-1, x, visited, pos + 1) == true
                || dfs(board, word, y, x+1, visited, pos + 1) == true
                || dfs(board, word, y, x-1, visited, pos + 1) == true)
            {
                return true;
            }
            // back to last step
            visited[y][x] = false;
        }
        
        return false;
    }
}


// Runtime: 76 ms, faster than 44.12% of Java online submissions for Word Search.
// Memory Usage: 36.9 MB, less than 69.79% of Java online submissions for Word Search.
// time complexity: O(m * n * 4^len(word))
// space complexity: O(m*n)