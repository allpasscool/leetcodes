class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> dp((n2 + 1), 0);
        int cur = 0, pre = 0;
        
        for (int i = 1; i <= n1; ++i) {
            pre = 0;
            for (int j = 1; j <= n2; ++j) {
                cur = dp[j];
                if (text1[i-1] == text2[j-1])
                    dp[j] = pre + 1;
                else
                    dp[j] = max(dp[j], dp[j-1]);
                pre = cur;
            }
        }
        
        return dp[n2];
    }
};

// Runtime: 16 ms, faster than 67.70% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 6.3 MB, less than 97.26% of C++ online submissions for Longest Common Subsequence.
// time complexity: O(n1 * n2)
// space complexity: O(min(n1, n2))
// https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)