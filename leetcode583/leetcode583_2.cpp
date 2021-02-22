class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1));
        
        for(int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0)
                    continue;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};

// Runtime: 12 ms, faster than 81.65% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 12.1 MB, less than 27.90% of C++ online submissions for Delete Operation for Two Strings.
// time complexity: O(m * n)
// space complexity: O(m * n)