class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset;
        
        for (auto& s: wordDict)
            hashset.insert(s);
        
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && hashset.find(s.substr(j, i - j)) != hashset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};

// Runtime: 16 ms, faster than 46.02% of C++ online submissions for Word Break.
// Memory Usage: 14.4 MB, less than 43.40% of C++ online submissions for Word Break.
// time complexity: O(n^2)
// space complexity: O(n)