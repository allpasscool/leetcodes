class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hist(128, 0); // for t
        
        for (char c: t)
            ++hist[c];
        
        int remaining = t.length();
        int left = 0, right = 0, min_start = 0, min_len = INT_MAX;
        
        while (right < s.length()) {
            // if (--hist[s[right++]] >= 0)
            //     remaining--;
            hist[s[right]]--;
            if (hist[s[right]] >= 0) {
                remaining--;
            }
            ++right;
            
            while (remaining == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }
                // if (++hist[s[left++]] > 0)
                //     ++remaining;
                ++hist[s[left]];
                if (hist[s[left]] > 0)
                    ++remaining;
                ++left;
            }
        }
        
        return min_len < INT_MAX ? s.substr(min_start, min_len) : "";
    }
};

// Runtime: 12 ms, faster than 83.61% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 10.1 MB, less than 78.00% of C++ online submissions for Minimum Window Substring.
// time complexity: O(S + T)
// space complexity: O(128)