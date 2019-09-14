class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (n, vector<int> (n, INT_MIN)));
        
        return max(0, dp(0, 0, 0, memo, grid));
    }
    
    int dp(int r1, int c1, int c2, vector<vector<vector<int>>>& memo, vector<vector<int>>& grid) {
        int r2 = r1 + c1 - c2;
        int n = memo.size();
        if (n == r1 || n == r2 || n == c1 || n == c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -99999;
        }
        else if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        else if (memo[r1][c1][c2] != INT_MIN) {
            return memo[r1][c1][c2];
        }
        else {
            int ans = grid[r1][c1];
            if (c1 != c2) {
                ans += grid[r2][c2];
            }
            ans += max(max(dp(r1, c1+1, c2+1, memo, grid), dp(r1+1, c1, c2+1, memo, grid)), 
                          max(dp(r1, c1+1, c2, memo, grid), dp(r1+1, c1, c2, memo, grid)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
};
// Runtime: 48 ms, faster than 46.44% of C++ online submissions for Cherry Pickup.
// Memory Usage: 22.8 MB, less than 25.00% of C++ online submissions for Cherry Pickup.
// time complexity: O(n^3)
// space complexity: O(n^3)