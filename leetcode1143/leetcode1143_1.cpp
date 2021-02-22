class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1));
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
};

// Runtime: 20 ms, faster than 56.90% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 12.9 MB, less than 40.68% of C++ online submissions for Longest Common Subsequence.
// time complexity: O(n1 * n2)
// space complexity: O(n1 * m2)
// https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)