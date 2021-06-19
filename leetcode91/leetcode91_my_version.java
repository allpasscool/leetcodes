class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int[] ways = new int[n];
        
        // base case
        // xxxxxxx | 5
        if (s.charAt(n - 1) != '0')
        {
            ways[n - 1] = 1;
        }
        // xxxxxx |2 | 5
        // xxxxxx | 25
        if (n > 1 && s.charAt(n - 2) != '0')
        {
            if (Integer.valueOf(s.substring(n - 2, n)) <= 26)
            {
                ways[n - 2]++;
            }
            
            ways[n - 2] += ways[n - 1];
        }
        
        for (int i = n - 3; i >= 0; i--)
        {
            // general case
            // xxxxxxx |3| 25 => |3|2|5| or |3|25|
            // xxxxxxx |32 | 5
            int counts = 0;
            if (s.charAt(i) != '0')
            {
                // xxxxxxxx | 3 25 => |2|5| or |25|
                counts += ways[i + 1];
                // xxxxxxxxx |32 |5. 32 should <= 26
                if (Integer.valueOf(s.substring(i, i + 2)) <= 26)
                {
                    counts += ways[i + 2];
                }
            }
            
            ways[i] = counts;
        }
        
        return ways[0];
    }
}

// Runtime: 1 ms, faster than 93.45% of Java online submissions for Decode Ways.
// Memory Usage: 37.7 MB, less than 38.18% of Java online submissions for Decode
// Ways.
// time complexity: O(n)
// space complexity: O(n)