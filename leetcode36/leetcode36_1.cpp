class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                if (c == '.') {
                    continue;
                }
                
                int box_num = i / 3 * 3 + j / 3;
                string row_seen = "row " + std::to_string(i) + " " + c;
                string column_seen = "column " + std::to_string(j) + " " + c;
                string box_seen = "box " + std::to_string(box_num) + " " + c;
                
                if (seen.find(row_seen) != seen.end()
                    || seen.find(column_seen) != seen.end()
                    || seen.find(box_seen) != seen.end()) {
                    return false;
                } else {
                    seen.insert(row_seen);
                    seen.insert(column_seen);
                    seen.insert(box_seen);
                }
            }
        }
        
        return true;
    }
};
// Runtime: 24 ms, faster than 16.89% of C++ online submissions for Valid Sudoku.
// Memory Usage: 11.5 MB, less than 15.53% of C++ online submissions for Valid Sudoku.
// time complexity: O(n), n is 9 * 9
// space complexity: O(3 * n)