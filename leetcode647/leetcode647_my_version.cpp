class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int len = 0;
            
            // palindromic substring with odd nums
            while (i - len >= 0 && i + len < s.length() && s[i + len] == s[i - len]) {
                ++count;
                ++len;
            }
            
            len = 0;
            while (i - len >= 0 && i + len < s.length() && s[i + 1 + len] == s[i - len]) {
                ++count;
                ++len;
            }
            // cout << count << endl;
        }
        
        return count;
    }
};


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Palindromic Substrings.
// Memory Usage: 8.6 MB, less than 72.00% of C++ online submissions for Palindromic Substrings.
// time complexity: O(n^2)
// space complexity: O(1)