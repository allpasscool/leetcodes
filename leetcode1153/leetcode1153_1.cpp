class Solution {
public:
    bool canConvert(string s1, string s2) {
        if (s1 == s2) return true;
        unordered_map<char, char> dp;
        for (int i = 0; i < s1.length(); ++i) {
            if (dp[s1[i]] != NULL && dp[s1[i]] != s2[i])
                return false;
            dp[s1[i]] = s2[i];
        }
        return set(s2.begin(), s2.end()).size() < 26;
    }
};

// https://leetcode.com/problems/string-transforms-into-another-string/discuss/355382/JavaC%2B%2BPython-Need-One-Unused-Character
// Runtime: 7 ms, faster than 35.44% of C++ online submissions for String Transforms Into Another String.
// Memory Usage: 7.2 MB, less than 99.30% of C++ online submissions for String Transforms Into Another String.
// time complexity: O(n)
// space complexity: O(26)