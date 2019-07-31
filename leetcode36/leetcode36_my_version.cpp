class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nums[10] = {0};
        
        //rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                if (c == '.') {
                    continue;
                } else if(nums[c - '0'] != (i+1)) {
                    nums[c - '0'] = i + 1;
                } else {
                    return false;
                }
            }
        }
        
        //reset nums
        for (int i = 0; i < 10; i++) {
            nums[i] = 0;
        }
        
        //columns
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                
                if (c == '.') {
                    continue;
                } else if (nums[c - '0'] != (i+1)) {
                    nums[c - '0'] = i + 1;
                } else {
                    return false;
                }
            }
        }
        
        //reset nums
        for (int j = 0; j < 10; j++) {
            nums[j] = 0;
        }
        
        //3x3 sub-boxes
        //row 3x3 sub-boxes
        for (int i = 0; i < 3; i++) {
            
            //column 3x3 sub-boxes
            for (int j = 0; j < 3; j++) {
                //each sub-box
                //row
                for (int k = 0; k < 3; k++) {
                    //column
                    for (int t = 0; t < 3; t++) {
                        char c = board[i * 3 + k][j * 3 + t];
                        
                        if (c == '.') {
                            continue;
                        } else if (nums[c - '0'] != (i * 3 + j + 1)) {
                            nums[c - '0'] = i * 3 + j + 1;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
// Runtime: 12 ms, faster than 91.89% of C++ online submissions for Valid Sudoku.
// Memory Usage: 9.3 MB, less than 96.38% of C++ online submissions for Valid Sudoku.
// time complexity: O(3 * n), n is 9 * 9
// space complexity: O(1)