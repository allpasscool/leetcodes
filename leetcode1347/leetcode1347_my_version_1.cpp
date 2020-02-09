class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count1(26), count2(26);
        
        for (auto c : s) {
            ++count1[c - 'a'];
        }
        for (auto c : t) {
            ++count2[c - 'a'];
        }
        
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += abs(count1[i] - count2[i]);
        }
        
        diff = (diff + 1) / 2;
        
        return diff;
    }
};


// Runtime: 88 ms, faster than 63.64% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// Memory Usage: 19 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// time complexity: O(n + m)
// space complexity: O(1)