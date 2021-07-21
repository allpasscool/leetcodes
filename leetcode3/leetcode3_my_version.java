class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> substr = new HashSet<>();
        int left = 0, right = 0;
        int maxLen = 0;
        
        while (right < s.length())
        {
            // has included this letter
            while (substr.contains(s.charAt(right)))
            {
                substr.remove(s.charAt(left));
                left++;
            }
            
            substr.add(s.charAt(right));
            right++;
            maxLen = Math.max(maxLen, right - left);
        }
        
        return maxLen;
    }
}

// Runtime: 7 ms, faster than 46.52% of Java online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 39.1 MB, less than 63.80% of Java online submissions for Longest Substring Without Repeating Characters.
// time complexity: O(n)
// space complexity: O(n)