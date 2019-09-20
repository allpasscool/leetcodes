class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return nums[0];
        }
        else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};

// Runtime: 4 ms, faster than 57.10% of C++ online submissions for House Robber.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for House Robber.
// time complexity: O(n)
// space complexity: O(n)