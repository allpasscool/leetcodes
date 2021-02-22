class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1));
        
        for(int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        
        return dp[word1.size()][word2.size()];
    }
};

// Runtime: 20 ms, faster than 61.59% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 12.1 MB, less than 39.06% of C++ online submissions for Delete Operation for Two Strings.
// time complexity: O(m * n)
// space complexity: O(m * n)