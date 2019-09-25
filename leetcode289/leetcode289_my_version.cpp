class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ny = board.size();
        int nx = board[0].size();
        auto tmp = board;
        
        for (int i = 0; i < ny; ++i) {
            for (int j = 0; j < nx; ++j) {
                int lives = 0;
                
                // left and down
                if (i - 1 >= 0 && j - 1 >= 0)
                    lives += board[i - 1][j - 1];
                // left
                if (j - 1 >= 0)
                    lives += board[i][j - 1];
                // left and up
                if (i + 1 < ny && j - 1 >= 0)
                    lives += board[i + 1][j - 1];
                // up
                if (i + 1 < ny)
                    lives += board[i + 1][j];
                // down
                if (i - 1 >= 0)
                    lives += board[i - 1][j];
                // right and down
                if (i - 1 >= 0 && j + 1 < nx)
                    lives += board[i - 1][j + 1];
                // right
                if (j + 1 < nx)
                    lives += board[i][j + 1];
                // right and up
                if (i + 1 < ny && j + 1 < nx)
                    lives += board[i + 1][j + 1];
                
                // when it is live
                if (board[i][j] == 1) {
                    // condition 1
                    if (lives < 2)
                        tmp[i][j] = 0;
                    // condition 3
                    else if (lives > 3)
                        tmp[i][j] = 0;
                }
                // when it is dead
                else {
                    // condition 4
                    if (lives == 3) 
                        tmp[i][j] = 1;
                }
            }
        }
        
        board = tmp;
        return;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 8.7 MB, less than 82.14% of C++ online submissions for Game of Life.
// time complexity: O(nx * ny)
// space complexity: O(nx * ny)