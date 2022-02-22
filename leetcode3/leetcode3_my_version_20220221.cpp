class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> counts;
        int left = 0, right = 0, n = s.size();
        int maxLen = 0;

        while (right < n)
        {
            char c = s[right];
            counts[c]++;

            while (counts[c] > 1)
            {
                counts[s[left]]--;
                left++;
            }

            right++;
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

// Runtime: 15 ms, faster than 71.26% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.3 MB, less than 71.88% of C++ online submissions for Longest Substring Without Repeating Characters.
// time complexity: O(n)
// space complexity: O(1)