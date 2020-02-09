class Solution {
public:
    int minSteps(string s, string t) {
        // vector<int> count1(26), count2(26);
        vector<int> count(26);
        
        for (auto c : s) {
            ++count[c - 'a'];
        }
        for (auto c : t) {
            count[c - 'a']--;
        }
        
        int diff = 0;
        for (int i = 0; i < 26; ++i) {
            diff += abs(count[i]);
        }
        
        diff = (diff + 1) / 2;
        
        return diff;
    }
};


// Runtime: 88 ms, faster than 63.64% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// Memory Usage: 18.9 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// time complexity: O(n + m)
// space complexity: O(1)
