class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ny = board.size();
        int nx = board[0].size();
        
        // 0 means dead, 1 means live
        // -1 means from dead to live
        // 2 means from live to dead
        for (int i = 0; i < ny; ++i) {
            for (int j = 0; j < nx; ++j) {
                int lives = 0;
                
                // left and down
                if (i - 1 >= 0 && j - 1 >= 0)
                    lives += board[i - 1][j - 1] > 0 ? 1 : 0;
                // left
                if (j - 1 >= 0)
                    lives += board[i][j - 1] > 0 ? 1 : 0;
                // left and up
                if (i + 1 < ny && j - 1 >= 0)
                    lives += board[i + 1][j - 1] > 0 ? 1 : 0;
                // up
                if (i + 1 < ny)
                    lives += board[i + 1][j] > 0 ? 1 : 0;
                // down
                if (i - 1 >= 0)
                    lives += board[i - 1][j] > 0 ? 1 : 0;
                // right and down
                if (i - 1 >= 0 && j + 1 < nx)
                    lives += board[i - 1][j + 1] > 0 ? 1 : 0;
                // right
                if (j + 1 < nx)
                    lives += board[i][j + 1] > 0 ? 1 : 0;
                // right and up
                if (i + 1 < ny && j + 1 < nx)
                    lives += board[i + 1][j + 1] > 0 ? 1 : 0;
                
                // when it is live
                if (board[i][j] == 1) {
                    // condition 1
                    if (lives < 2)
                        board[i][j] = 2;
                    // condition 3
                    else if (lives > 3)
                        board[i][j] = 2;
                }
                // when it is dead
                else {
                    // condition 4
                    if (lives == 3) 
                        board[i][j] = -1;
                }
            }
        }
        
        // update to next state
        for (int i = 0; i < ny; ++i) {
            for (int j = 0; j < nx; ++j) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
        
        return;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 8.7 MB, less than 89.29% of C++ online submissions for Game of Life.
// time complexity: O(nx * ny)
// space complexity: O(1)