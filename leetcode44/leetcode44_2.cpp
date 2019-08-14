class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        
        // base cases
        if (p == s || p == "*") {
            return true;
        }
        if (p.empty() || s.empty()) {
            return false;
        }
        
        // init all matrix except [0][0] element as False
        vector<vector<bool>> dp ((p_len + 1), vector<bool> (s_len + 1, false));
        dp[0][0] = true;
        
        // DP compute
        for (int p_idx = 1; p_idx <= p_len; p_idx++) {
            // the current character in the pattern is '*'
            if (p[p_idx - 1] == '*'){
                int s_idx = 1;
                
                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while (!dp[p_idx - 1][s_idx - 1] && (s_idx < s_len + 1)) {
                    s_idx++;
                }
                
                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                dp[p_idx][s_idx - 1] = dp[p_idx - 1][s_idx - 1];
                
                // If (string) matches (patterns),
                // When (string)(whatever_characters) matches (pattern)* as well
                while (s_idx <= s_len) {
                    dp[p_idx][s_idx] = true;
                    s_idx++;
                }
            } else if (p[p_idx - 1] == '?') { // the current character in the pattern is '?'
                for (int s_idx = 1; s_idx <= s_len; s_idx++) {
                    dp[p_idx][s_idx] = dp[p_idx - 1][s_idx - 1];
                }
            } else { // the current character in the pattern is not '*' or '?'
                for (int s_idx = 1; s_idx <= s_len; s_idx++) {
                    // match is possible if there is a previous match
                    // and current character are the same
                    dp[p_idx][s_idx] = dp[p_idx - 1][s_idx - 1] 
                        && p[p_idx - 1] == s[s_idx - 1];
                }
            }
        }
        
        return dp[p_len][s_len];
    }
};
// Runtime: 60 ms, faster than 47.61% of C++ online submissions for Wildcard Matching.
// Memory Usage: 11.7 MB, less than 46.15% of C++ online submissions for Wildcard Matching.
// time complexity: O(s * p)
// space complexity: O(s * p)