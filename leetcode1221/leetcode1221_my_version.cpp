class Solution {
public:
    int balancedStringSplit(string s) {
        int output = 0;
        int count = 0; // R + 1, L - 1
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'R')
                ++count;
            else
                count--;
            
            if (count == 0)
                ++output;
        }
        
        return output;
    }
};


// Runtime: 4 ms, faster than 57.84% of C++ online submissions for Split a String in Balanced Strings.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Split a String in Balanced Strings.
// time complexity: O(n)
// space complexity: O(1)