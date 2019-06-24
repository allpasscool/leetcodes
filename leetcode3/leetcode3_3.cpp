class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> charmap;
        int n = s.length();
        int ans = 0;
        for(int i = 0, j = 0; j < n && i < n; j++){
            if (charmap.find(s[j]) != charmap.end()){
                i = std::max(charmap.find(s[j])->second, i);
            }
            ans = std::max(ans, j - i + 1);
            charmap[s[j]] = j + 1;
        }
        return ans;
    }
};
//Runtime: 12 ms, faster than 90.88% of C++ online submissions for Longest Substring Without Repeating Characters.
//Memory Usage: 11 MB, less than 49.78% of C++ online submissions for Longest Substring Without Repeating Characters.
//Time complexity : O(n). Index j will iterate n times.
//Space complexity (HashMap) : O(min(m, n)). Same as the previous approach.