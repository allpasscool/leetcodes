class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nx = obstacleGrid.size();
        if (nx == 0) 
            return 0;
        int ny = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        // although to target point won't have unique path > INT_MAX
        // to some certain point which can't from that point to target point
        // this certain point will have unique paths > INT_MAX
        // therefore, we use long long
        vector<vector<long long>> dp(nx, vector<long long> (ny, 0)); // dp[right][down] go right and go down
        dp[0][0] = 1;
        
        // how far from start point
        for (int i = 1; i <= (nx + ny - 2); ++i) {
            // if there is a block line?
            bool pass = false;
            
            // how many right
            for (int j = min(i, nx - 1); j >= 0; --j) {
                int down = i - j;
                
                if (down >= ny || obstacleGrid[j][down] == 1) {
                    continue;
                }
                
                long long num_from_left = 0;
                if (j > 0 && obstacleGrid[j - 1][down] == 0)
                    num_from_left = dp[j - 1][down];
                long long num_from_up = 0;
                if (down > 0 && down < ny && obstacleGrid[j][down - 1] == 0)
                    num_from_up = dp[j][down - 1];
                
                dp[j][down] = num_from_left + num_from_up;
                
                if (dp[j][down] > 0)
                    pass = true;
            }
            
            if (!pass)
                return 0;
        }
        
        return (int)dp[nx - 1][ny - 1];
    }
};

// Runtime: 4 ms, faster than 74.53% of C++ online submissions for Unique Paths II.
// Memory Usage: 9.4 MB, less than 30.00% of C++ online submissions for Unique Paths II.
// time comlexity: O(n)
// space complexity: O(n)