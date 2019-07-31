class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_seen[10][10] = {false};
        bool column_seen[10][10] = {false};
        bool box_seen[10][10] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                if (c == '.') {
                    continue;
                }
                
                int box_num = i / 3 * 3 + j / 3;
                int num = c - '0';
                
                if (row_seen[i][num] || column_seen[j][num] || box_seen[box_num][num]) {
                    return false;
                } else {
                    row_seen[i][num] = true;
                    column_seen[j][num] = true;
                    box_seen[box_num][num]  = true;
                }
            }
        }
        
        return true;
    }
};
// Runtime: 12 ms, faster than 91.89% of C++ online submissions for Valid Sudoku.
// Memory Usage: 9.3 MB, less than 93.19% of C++ online submissions for Valid Sudoku.
// time complexity: O(n), n is 9 * 9
// space complexity: O(3 * n)