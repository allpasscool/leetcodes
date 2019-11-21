class Solution {
public:
    int countSubstrings(string s) {
        // first step, make string become $#a#b#c#@ if s = abc
        vector<char> new_s(2 * s.length() + 3);
        new_s[0] = '$';
        new_s[1] = '#';
        new_s[new_s.size() - 1] = '@';
        int pos = 2;
        
        for (char c: s) {
            new_s[pos] = c;
            ++pos;
            new_s[pos] = '#';
            ++pos;
        }
        // now we have $#a#b#c#@
        
        // we use pali to store each pali[i] as i is the center, and the len of palindromic substrings
        vector<int> pali(new_s.size());
        int center = 0; // current center
        int right = 0; // right bound, which is max palindromic substring from center
        
        for (int i = 1; i < new_s.size() - 1; ++i) {
            // mirror position which center is "center"
            int mirr = 2 * center - i;
            
            // if current i is within the palidromic substring which center is "cetner"
            if (i < right) {
                pali[i] = min(right - i, pali[mirr]);
            }
            
            // try to expand
            while (new_s[i + pali[i] + 1] == new_s[i - pali[i] - 1])
                ++pali[i];
            
            // if new palindromic substring will be out of right bound
            if (i + pali[i] > right) {
                center = i;
                right = i + pali[i];
            }
        }
        
        int ans = 0;
        for (int v : pali) 
            ans += (v + 1) / 2;
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 90.08% of C++ online submissions for Palindromic Substrings.
// Memory Usage: 8.9 MB, less than 52.00% of C++ online submissions for Palindromic Substrings.
// time complexity: O(n)
// space complexity: O(n)
// https://www.youtube.com/watch?v=nbTSfrEfo6M