class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        // dp[p1][p2] = longest common subsequence to p1 p2
        vector<vector<int>> dp(n1, vector<int> (n2, 0));
        int ans = 0;
        
        // base cases
        // i = 0, j = 0
        dp[0][0] = (int) (text1[0] == text2[0]);
        // i = 0
        for (int j = 1; j < n2; ++j) {
            // text1[0] == text2[j] || text1[0] != text2[j]
            dp[0][j] = max((int) (text1[0] == text2[j]), dp[0][j-1]);
        }
        //j = 0
        for (int i = 1; i < n1; ++i) {
            dp[i][0] = max((int) (text1[i] == text2[0]), dp[i-1][0]);
        }
        
        // general cases
        for (int i = 0; i < n1; ++i) {
            
            for (int j = 0; j < n2; ++j) {
                int comp = text1[i] == text2[j];
                
                if (i > 0 && j > 0) {
                    // text1[i] == text2[j] = dp[i -1][j - 1] + 1
                    // text[i] != text[j] = max( dp[i][j - 1], dp[i - 1][j]
                    dp[i][j] = max(max(dp[i - 1][j - 1] + comp, dp[i][j - 1]), dp[i-1][j]);
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};

// Runtime: 32 ms, faster than 22.80% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 12.9 MB, less than 40.68% of C++ online submissions for Longest Common Subsequence.
// time complexity: O(n1 * n2)
// space complextiy: O(n1 * n2)