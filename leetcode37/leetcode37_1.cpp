class Solution {
public:
    // box size
    int n = 3;
    // row size
    int N = n * n;

    int rows[9][10] = {0};
    int columns[9][10] = {0};
    int boxes[9][10] = {0};

    bool sudoku_solved = false;
    
    bool couldPlace(int d, int row, int col) {
        /*
        check if one could place a number d in (row, col) cell
        */
        int idx = (row / n) * n + col / n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }
    
    void placeNumber(int d, int row, int col, vector<vector<char>>& board) {
        /*
        place a number d in (row, col) cell
        */
        int idx = (row / n) * n + col / n;
        
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d + '0');
    }
    
    void removeNumber(int d, int row, int col, vector<vector<char>>& board) {
        /*
        remove a number which didn't lead to a solution
        */
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }
    
    void placeNextNumbers(int row, int col, vector<vector<char>>& board) {
        /*
        call backtrack function in recursion
        to continue to place numbers
        until the moment we have a solution
        */
        // if we're in the last cell
        //that means we have the solution
        if ((col == N - 1) && (row == N - 1)) {
            sudoku_solved = true;
        } else { // if not yet
            // if we're in the end of the row
            // go to the next row
            if (col == N - 1) {
                backtrack(row + 1, 0, board);
            } else { // go to the next column
                backtrack(row, col + 1, board);
            }
        }
    }
    
    void backtrack(int row, int col, vector<vector<char>>& board) {
        /*
        Backtracking
        */
        // if the cell is empty
        if (board[row][col] == '.') {
            // iterate over all numbers from 1 to 9
            for (int d = 1; d < 10; d++) {
                if (couldPlace(d, row, col)) {
                    placeNumber(d, row, col, board);
                    placeNextNumbers(row, col, board);
                    // if sudoku is solved, there is no need to backtrack
                    // since the single unique solution is promised
                    if (!sudoku_solved) removeNumber(d, row, col, board);
                }
            }
        } else {
            placeNextNumbers(row, col, board);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        // init rows, columns and boxes
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = num - '0';
                    placeNumber(d, i, j, board);
                }
            }
        }
        
        backtrack(0, 0, board);
    }
};

// Runtime: 8 ms, faster than 85.34% of C++ online submissions for Sudoku Solver.
// Memory Usage: 8.7 MB, less than 95.50% of C++ online submissions for Sudoku Solver.
// time complexity: O(10 ^ N)
// space complexity: O(N)