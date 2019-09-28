class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset;
        
        for (auto& s: wordDict)
            hashset.insert(s);
        
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true; // empty string
        
        // from every i position, check if you can make word ending here
        for (int i = 1; i <= s.length(); ++i) {
            // if we can make a word from j to i
            // we want to check if we can make a word till j first
            for (int j = i; j >= 0; j--) {
                if (dp[j] && hashset.find(s.substr(j, i - j)) != hashset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};

// Runtime: 8 ms, faster than 76.42% of C++ online submissions for Word Break.
// Memory Usage: 10.8 MB, less than 64.15% of C++ online submissions for Word Break.
// time complexity: O(n^2)
// space complexity: O(n)