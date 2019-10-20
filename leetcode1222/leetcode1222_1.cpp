class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool queen_loc[8][8] = {};
        
        // place queens
        for (auto& q : queens) {
            queen_loc[q[0]][q[1]] = true;
        }
        
        // find queens can attack the king
        vector<vector<int>> output;
        
        // decide left or right or stay in the same x
        for (int i = -1; i <= 1; ++i) {
            // decide up or down or stay in the same y
            for (int j = -1; j <= 1; ++j) {
                // this case won't move
                if (i == 0 && j == 0)
                    continue;
                
                int x = king[0] + i, y = king[1] + j;
                // range is 8 * 8
                while (min(x, y) >= 0 && max(x, y) < 8) {
                    if (queen_loc[x][y]) {
                        output.push_back({x, y});
                        break;
                    }
                    
                    x += i;
                    y += j;
                }
            }
        }
        
        return output;
    }
};

// Runtime: 4 ms, faster than 92.82% of C++ online submissions for Queens That Can Attack the King.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Queens That Can Attack the King.
// time complexity: O(# of queens)
// space complexity: O(1)

// vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
//     bool b[8][8] = {};
//     for (auto& q : queens) b[q[0]][q[1]] = true;
//     vector<vector<int>> res;
//     for (auto i = -1; i <= 1; ++i)
//         for (auto j = -1; j <= 1; ++j) {
//             if (i == 0 && j == 0) continue;
//             auto x = k[0] + i, y = k[1] + j;
//             while (min(x, y) >= 0 && max(x, y) < 8) {
//                 if (b[x][y]) {
//                     res.push_back({ x, y });
//                     break;
//                 }
//                 x += i, y += j;
//             }
//         }
//     return res;
// }
// https://leetcode.com/problems/queens-that-can-attack-the-king/discuss/403755/C%2B%2B-Tracing
