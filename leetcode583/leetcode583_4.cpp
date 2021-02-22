class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1);
        int cur = 0, pre = 0;
        
        for(int i = 0; i <= word1.size(); ++i) {
            pre = 0;
            for (int j = 0; j <= word2.size(); ++j) {
                cur = dp[j];
                if (i == 0 || j == 0)
                    dp[j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = 1 + min(dp[j], dp[j - 1]);
                
                pre = cur;
            }
        }
        
        return dp[word2.size()];
    }
};

// Runtime: 12 ms, faster than 81.65% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 6.7 MB, less than 97.00% of C++ online submissions for Delete Operation for Two Strings.
// time complexity: O(m * n)
// space complexity: O(n)