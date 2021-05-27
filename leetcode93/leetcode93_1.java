public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>();
        int len = s.length();
        
        // first field from 0 - (i-1)
        for (int i = 1; i < 4 && i < len - 2; i++)
        {
            // second field from i - (j - 1)
            for (int j = i + 1; j < i + 4 && j < len - 1; j++)
            {
                // third field from j - (k - 1)
                // fourth field from k - len
                for(int k = j + 1; k < j + 4 && k < len; k++)
                {
                    String s1 = s.substring(0, i), s2 = s.substring(i, j), 
                                s3 = s.substring(j, k), s4 = s.substring(k, len);
                    
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                    {
                        res.add(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return res;
    }
    
    private boolean isValid(String s)
    {
        // 0 - 255 || can't be empty || 01 is not valid || < 256
        if(s.length() > 3 || s.length() == 0 || (s.charAt(0) == '0' && s.length() > 1) 
           || Integer.parseInt(s) > 255)
        {
            return false;
        }
        
        return true;
    }
}

// Runtime: 8 ms, faster than 21.71% of Java online submissions for Restore IP Addresses.
// Memory Usage: 39 MB, less than 74.35% of Java online submissions for Restore IP Addresses.
// time complexity: O(2^n) == O(1)
// space complexity: O(2^n) == O(1)
// https://leetcode.com/problems/restore-ip-addresses/discuss/30949/My-code-in-Java