class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[128] = {0};
        int n = s.length();
        int ans = 0;
        for(int i = 0, j = 0; i < n && j < n; j++){
            i = std::max(index[s[j]], i);
            ans = std::max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};
//Runtime: 4 ms, faster than 99.70% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 9.1 MB, less than 88.20% of C++ online submissions for Longest Substring Without Repeating Characters.
//Time complexity : O(n)O(n). Index jj will iterate nn times.
//Space complexity (Table): O(m)O(m). mm is the size of the charset.