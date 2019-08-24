class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // reframe the problem
        int n = nums.size() + 2;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        // dp will store the results of our calls
        vector<vector<int>> dp (n, vector<int> (n, 0));
        
        // iterate over dp and incrementally build up to dp[0][n - 1]
        for (int left = n - 3; left >= 0; left--) {
            for (int right = left + 2; right < n; right++) {
                for (int i = left + 1; i < right; i++) {
                    // same formula to get the best score from (left, right) as before
                    dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
// Runtime: 20 ms, faster than 54.24% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.3 MB, less than 75.00% of C++ online submissions for Burst Balloons.
// time complexity: O(n^3)
// space complexity: O(n^2)