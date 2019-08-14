class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        int s_idx = 0, p_idx = 0;
        int star_idx = -1, s_tmp_idx = -1;
        
        while (s_idx < s_len) {
            // If the pattern character = string character
            // or pattern character = '?'
            if (p_idx < p_len && (p[p_idx] == '?' || p[p_idx] == s[s_idx])) {
                p_idx++;
                s_idx++;
            } 
             // If pattern character = '*'
            else if (p_idx < p_len && p[p_idx] == '*') {
                // check the situation
                // when '*' matches no characters
                star_idx = p_idx;
                s_tmp_idx = s_idx;
                p_idx++;
            } 
            // If pattern character != string character
            // or pattern is used up
            // and there was no '*' character in pattern
            else if (star_idx == -1) {
                return false;
            }
            // If pattern character != string character
            // or pattern is used up
            // and there was '*' character in pattern before
            else {
                // Backtrack: check the situation
                // when '*' matches one more character
                p_idx = star_idx + 1;
                s_idx = s_tmp_idx + 1;
                s_tmp_idx = s_idx;
            }
        }
        
        // the remaining characters in the pattern should all be '*' characters
        for (int i = p_idx; i < p_len; i++) {
            if (p[i] != '*') {
                return false;
            }
        }
        
        return true;
    }
};
// Runtime: 4 ms, faster than 98.79% of C++ online submissions for Wildcard Matching.
// Memory Usage: 8.9 MB, less than 73.08% of C++ online submissions for Wildcard Matching.
// time complexity: O(s * p)
// space complexity: O(1)