class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        int steps = 0;
        int start_pos = 0, farthest = 0;//from where can reach the farest
        for (int i = 0; i < n - 1; i++) {
            
            //to this position is biger than minimum to next
            if (dp[i] > dp[i + 1] || i + nums[i] < farthest) {
                continue;
            }
            
            //current position can jump
            for (int j = 1; i + j < n && j <= nums[i]; j++) {
                if (i + j + nums[i + j] >= farthest) {
                    farthest = i + j + nums[i + j];
                    start_pos = i + j;
                }
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
            
            // steps++;
        }
        
        return dp[n - 1];
    }
};
// Runtime: 12 ms, faster than 70.58% of C++ online submissions for Jump Game II.
// Memory Usage: 10.3 MB, less than 55.00% of C++ online submissions for Jump Game II.
// time complexity: O(n^2)
// space complexity: O(n)