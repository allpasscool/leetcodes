class Solution {
    int index = 0;
    
    String decodeString(String s) {
        StringBuilder result = new StringBuilder();
        
        while (index < s.length() && s.charAt(index) != ']') 
        {
            // not digit
            if (!Character.isDigit(s.charAt(index)))
                result.append(s.charAt(index++));
            // is digit
            else 
            {
                int k = 0;
                // build k while next character is a digit
                while (index < s.length() && Character.isDigit(s.charAt(index)))
                    k = k * 10 + s.charAt(index++) - '0';
                // ignore the opening bracket '['    
                index++;
                String decodedString = decodeString(s);
                // ignore the closing bracket ']'
                index++;
                // build k[decodedString] and append to the result
                while (k-- > 0)
                    result.append(decodedString);
            }
        }
        return new String(result);
    }
}


// Runtime: 0 ms, faster than 100.00% of Java online submissions for Decode String.
// Memory Usage: 37.1 MB, less than 66.09% of Java online submissions for Decode String.
// Assume, n is the length of the string s.
// Time Complexity: O(maxK * n) as in Approach 2
// Space Complexity: O(n). This is the space used to store the internal call stack used for recursion. 
// As we are recursively decoding each nested pattern, the maximum depth of recursive call stack would not be more than n