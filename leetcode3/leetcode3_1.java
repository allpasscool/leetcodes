public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        
        return ans;
    }
}

// Runtime: 6 ms, faster than 64.18% of Java online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 38.9 MB, less than 81.48% of Java online submissions for Longest Substring Without Repeating Characters.
// time complexity: O(n)
// space complexity: O(n)
// Solution 3