class Solution {
    String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder currentString = new StringBuilder();
        int k = 0;
        
        for (char ch : s.toCharArray()) {
            
            // digit
            if (Character.isDigit(ch)) 
            {
                k = k * 10 + ch - '0';
            } 
            else if (ch == '[') 
            {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = new StringBuilder();
                k = 0;
            } 
            else if (ch == ']')
            {
                StringBuilder decodedString = stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.pop(); currentK > 0; currentK--) {
                    decodedString.append(currentString);
                }
                currentString = decodedString;
            } 
            // letter(alphabetics)
            else 
            {
                currentString.append(ch);
            }
        }
        return currentString.toString();
    }
}


// Runtime: 0 ms, faster than 100.00% of Java online submissions for Decode String.
// Memory Usage: 37.1 MB, less than 54.70% of Java online submissions for Decode String.
// Assume, n is the length of the string s.
// Time Complexity: O(maxK⋅n), where maxK is the maximum value of k and n is the length of a given string s. 
// We traverse a string of size n and iterate k times to decode each pattern of form k[string]. 
// This gives us worst case time complexity as O(maxK⋅n).
// Space Complexity: O(m+n), where m is the number of letters(a-z) and n is the number of digits(0-9) in string s. 
// In worst case, the maximum size of stringStack and countStack could be m and n respectively.