class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // if k / nums[j] < dp[i][j - 1]
                // means that nums[j] * dp[i][j - 1] >= k
                // , which is not we want
                // we check this to avoid > INT_MAX
                if (k / nums[j] < dp[i][j - 1]) {
                    dp[i][j] = k;
                }
                else {
                    dp[i][j] = dp[i][j - 1] * nums[j];
                }
            }
        }
        
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] < k) {
                    // cout << i << ", " << j << endl;
                    count++;
                }
            }
        }
        
        return count;
    }
};
// Memory Limit Exceeded
// time complexity: O(n^2)
// space complexity: O(n^2)