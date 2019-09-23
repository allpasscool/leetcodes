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
        vector<long long> dp(nx, 0); // dp[right][down] go right and go down
        dp[0] = 1;
        
        // go down, next row
        for (int down = 0; down < ny; ++down) {
            // go right
            for (int right = 0; right < nx; ++right) {
                if (obstacleGrid[right][down] == 1) {
                    dp[right] = 0;
                    continue;
                }
                
                if (right > 0)
                    dp[right] += dp[right - 1];
            }
        }
        
        return dp[nx - 1];
    }
};

// Runtime: 4 ms, faster than 74.53% of C++ online submissions for Unique Paths II.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Unique Paths II.
// time complexity: O(nx * ny)
// space complexity: O(nx)