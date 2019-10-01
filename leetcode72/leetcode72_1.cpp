class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        
        // if one of the strings is empty
        if (n == 0 || m == 0)
            return n + m;
        
        // array to stroe the convertion history
        // dp[i][j] means when word1 is i long and word2 is j long
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        // init boundaries
        // when word2 is empty
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        // when word1 is empty
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = i;
        }
        
        // DP compute
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int left = dp[i - 1][j];
                int down = dp[i][j - 1];
                int left_down = dp[i - 1][j - 1];
                
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = 1 + min(min(left, down), left_down);
                }
                else {
                    dp[i][j] = 1 + min(min(left, down), left_down - 1);
                }
            }
        }
        
        return dp[n][m];
    }
};

// Runtime: 8 ms, faster than 92.29% of C++ online submissions for Edit Distance.
// Memory Usage: 11.4 MB, less than 59.38% of C++ online submissions for Edit Distance.
// time complexity: O(nm)
// space complexity: O(nm)