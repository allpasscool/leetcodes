class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> hashmap = new HashMap<>();
        int first_non_dup = Integer.MAX_VALUE;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            // not exist in hashmap
            if (!hashmap.containsKey(s.charAt(i)))
                hashmap.put(s.charAt(i), i);
            else
                hashmap.put(s.charAt(i), -1);
        }
        
        for (int i = 0; i < 26; i++) {
            char c = (char)('a' + i);
            
            if (hashmap.containsKey(c) 
                && hashmap.get(c) != -1) {
                first_non_dup = Math.min(first_non_dup, hashmap.get(c));
            }
            
            hashmap.put(c, i);
        }
        
        if (first_non_dup == Integer.MAX_VALUE)
            first_non_dup = -1;
        
        return first_non_dup;
    }
}

// Runtime: 18 ms, faster than 58.45% of Java online submissions for First Unique Character in a String.
// Memory Usage: 39.5 MB, less than 50.75% of Java online submissions for First Unique Character in a String.
// time complexity: O(n)
// space complexity: O(1) // hashmap only has 26