class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        // dp[p1][p2] = longest common subsequence to p1 p2
        vector<vector<int>> dp(n1, vector<int> (n2, 0));
        int ans = 0;
        
        for (int i = 0; i < n1; ++i) {
            
            for (int j = 0; j < n2; ++j) {
                int comp = text1[i] == text2[j];
                
                if (i > 0 && j > 0) {
                    // text1[i] == text2[j] = dp[i -1][j - 1] + 1
                    // text[i] != text[j] = dp[i][j - 1]
                    dp[i][j] = max(dp[i - 1][j - 1] + comp, dp[i][j - 1]);
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                else {
                    dp[i][j] = comp;
                    if (i > 0) {
                        dp[i][j] = max(dp[i][j], dp[i-1][0]);
                    }
                    else if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[0][j-1]);
                    }
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};

// Runtime: 40 ms, faster than 14.29% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 12.8 MB, less than 40.68% of C++ online submissions for Longest Common Subsequence.
// time complexity: O(n1 * n2)
// space complexity: o(n1 * n2)