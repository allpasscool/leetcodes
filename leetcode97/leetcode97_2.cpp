class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        
        if (n3 != n1 + n2)
            return false;
        
        vector<vector<bool>> dp(n1 + 1, vector<bool> (n2 + 1, false));
        
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; j++) {
                // length of s3 is 0, s1 and s2 is 0, so is true
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                // when s1 is 0, can s2 build s3?
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                // when s2 is 0, can s1 build s3?
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                // when we have i - 1 s1 and j s2 and last element is s1 i - 1
                // or
                // when we have i s1 and j - 1 s2 and last element is s2 j - 1
                else 
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dp[n1][n2];
    }
};

// Runtime: 8 ms, faster than 27.18% of C++ online submissions for Interleaving String.
// Memory Usage: 8.7 MB, less than 23.81% of C++ online submissions for Interleaving String.
// time complexity: O(n1 * n2)
// space complexity: O(n1 * n2)