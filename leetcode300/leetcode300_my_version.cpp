class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        vector<int> dp(n, 0);
        int output = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int longest_sub = 0;
            
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j])
                    longest_sub = max(longest_sub, dp[j]);
            }
            
            dp[i] = longest_sub + 1;
            output = max(output, dp[i]);
        }
        
        return output;
    }
};

// Runtime: 32 ms, faster than 63.94% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 8.7 MB, less than 64.06% of C++ online submissions for Longest Increasing Subsequence.
// time complexity: O(n^2)
// space complexity: O(n)