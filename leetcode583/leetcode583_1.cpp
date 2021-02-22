class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int> (word2.size() + 1));
        
        return word1.size() + word2.size() - 2 * lcs(word1, word2, word1.size(), word2.size(), memo);
    }
    
    int lcs(string& word1, string& word2, int m, int n, vector<vector<int>>& memo) {
        if (m == 0 || n == 0)
            return 0;
        if (memo[m][n] > 0)
            return memo[m][n];
        if (word1[m - 1] == word2[n - 1])
            memo[m][n] = 1 + lcs(word1, word2, m - 1, n - 1, memo);
        else
            memo[m][n] = max(lcs(word1, word2, m, n - 1, memo),
                            lcs(word1, word2, m - 1, n, memo));
        
        return memo[m][n];
    }
};

// Runtime: 144 ms, faster than 8.69% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 12.1 MB, less than 27.90% of C++ online submissions for Delete Operation for Two Strings.
// time complexity: O(m * n)
// space complexity: O(m * n)