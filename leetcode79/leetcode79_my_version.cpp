class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
private:
    unordered_map<string, bool> visited;
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int pos) {
        string cur = to_string(row) + "and" + to_string(col);
        if (visited[cur]) {
            return false;
        }
        if (pos == word.length()) {
            return true;
        }
        
        visited[cur] = true;
        
        // up
        if (row - 1 >= 0 && board[row - 1][col] == word[pos]) {
            
            if (dfs(board, row - 1, col, word, pos + 1)) {
                return true;
            }
        }
        
        // down
        if (row + 1 < board.size() && board[row + 1][col] == word[pos]) {
            if (dfs(board, row + 1, col, word, pos + 1)) {
                return true;
            }
        }
        
        // left
        if (col - 1 >= 0 && board[row][col - 1] == word[pos]) {
            if (dfs(board, row, col - 1, word, pos + 1)) {
                return true;
            }
        }
        // right
        if (col + 1 < board[row].size() && board[row][col + 1] == word[pos]) {
            if (dfs(board, row, col + 1, word, pos + 1)) {
                return true;
            }
        }
        
        visited[cur] = false;
        
        return false;
    }
};


// Runtime: 176 ms, faster than 37.22% of C++ online submissions for Word Search.
// Memory Usage: 13.6 MB, less than 52.94% of C++ online submissions for Word Search.
// time complexity: O(n * 4^L)
// space complexity: O(n)