class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26);
        
        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i] - 'a'];
            count[t[i] - 'a']--;
        }
        
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += abs(count[i]);
        }
        
        diff = (diff + 1) >> 1;
        
        return diff;
    }
};


// Runtime: 92 ms, faster than 63.64% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// Memory Usage: 18.8 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// time complexity: O(n)
// space complexity: O(1)