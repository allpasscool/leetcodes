class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        pair<int, int> right_col = {king[0], king[1]}, left_col = {king[0], king[1]};
        pair<int, int> up_row = {king[0], king[1]}, down_row = {king[0], king[1]};
        pair<int, int> right_up = {king[0], king[1]}, right_down = {king[0], king[1]}, left_up = {king[0], king[1]}, left_down = {king[0], king[1]};
        
        for (int i = 0; i < queens.size(); ++i) {
            
            // right
            if (queens[i][0] == right_col.first
               && queens[i][1] > king[1] && king[1] == right_col.second) {
                right_col.second = queens[i][1];
                continue;
            }
            else if (queens[i][0] == right_col.first
               && queens[i][1] > king[1] && queens[i][1] < right_col.second) {
                right_col.second = queens[i][1];
                continue;
            }
            
            // left
            else if (queens[i][0] == left_col.first
               && queens[i][1] < king[1] && king[1] == left_col.second) {
                left_col.second = queens[i][1];
                continue;
            }
            else if (queens[i][0] == left_col.first
               && queens[i][1] < king[1] && queens[i][1] > left_col.second) {
                left_col.second = queens[i][1];
                continue;
            }
            
            // up
            else if (queens[i][1] == up_row.second
               && queens[i][0] > king[0] && king[0] == up_row.first) {
                up_row.first = queens[i][0];
                continue;
            }
            else if (queens[i][1] == up_row.second
               && queens[i][0] > king[0] && queens[i][0] < up_row.first) {
                up_row.first = queens[i][0];
                continue;
            }
            
            // down
            else if (queens[i][1] == down_row.second
               && queens[i][0] < king[0] && king[0] == down_row.first) {
                down_row.first = queens[i][0];
                continue;
            }
            else if (queens[i][1] == down_row.second
               && queens[i][0] < king[0] && queens[i][0] > down_row.first) {
                down_row.first = queens[i][0];
                continue;
            }
            
            // right up
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] > king[0] && queens[i][1] > king[1]
               && king[0] == right_up.first) {
                right_up.first = queens[i][0];
                right_up.second = queens[i][1];
                continue;
            }
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] > king[0] && queens[i][1] > king[1]
               && queens[i][0] < right_up.first) {
                right_up.first = queens[i][0];
                right_up.second = queens[i][1];
                continue;
            }
            
            
            // right down
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] < king[0] && queens[i][1] > king[1]
               && king[0] == right_down.first) {
                right_down.first = queens[i][0];
                right_down.second = queens[i][1];
                continue;
            }
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] < king[0] && queens[i][1] > king[1]
               && queens[i][0] > right_down.first) {
                right_down.first = queens[i][0];
                right_down.second = queens[i][1];
                continue;
            }
            
            // left up
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] > king[0] && queens[i][1] < king[1]
               && king[0] == left_up.first) {
                left_up.first = queens[i][0];
                left_up.second = queens[i][1];
                continue;
            }
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] > king[0] && queens[i][1] < king[1]
               && queens[i][0] < left_up.first) {
                left_up.first = queens[i][0];
                left_up.second = queens[i][1];
                continue;
            }
            
            // left down
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] < king[0] && queens[i][1] < king[1]
               && king[0] == left_down.first) {
                left_down.first = queens[i][0];
                left_down.second = queens[i][1];
                continue;
            }
            else if (abs(queens[i][0] - king[0]) == abs(queens[i][1] - king[1])
               && queens[i][0] < king[0] && queens[i][1] < king[1]
               && queens[i][0] > left_down.first) {
                left_down.first = queens[i][0];
                left_down.second = queens[i][1];
                continue;
            }
            
        }
        
        vector<vector<int>> output;
        
        // left
        if (left_col.second != king[1])
            output.push_back({left_col.first, left_col.second});
        // right
        if (right_col.second != king[1])
            output.push_back({right_col.first, right_col.second});
        
        // up
        if (up_row.first != king[0])
            output.push_back({up_row.first, up_row.second});
        
        // down
        if (down_row.first != king[0])
            output.push_back({down_row.first, down_row.second});
        
        // right up
        if (right_up.first != king[0])
            output.push_back({right_up.first, right_up.second});
        
        // right down
        if (right_down.first != king[0])
            output.push_back({right_down.first, right_down.second});
        
        // left up
        if (left_up.first != king[0])
            output.push_back({left_up.first, left_up.second});
        
        // left down
        if (left_down.first != king[0])
            output.push_back({left_down.first, left_down.second});
        
        // output.push_back({down_row.first, down_row.second});
        
        return output;
    }
};

// Runtime: 4 ms, faster than 92.82% of C++ online submissions for Queens That Can Attack the King.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Queens That Can Attack the King.
// time complexity: O(# of queen)
// space complexity: O(1)