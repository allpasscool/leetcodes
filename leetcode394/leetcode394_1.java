class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ']') {
                List<Character> decodedString = new ArrayList<>();
                
                // get the encoded string
                while (stack.peek() != '[') {
                    decodedString.add(stack.pop());
                }
                
                // pop [ from the stack
                stack.pop();
                int base = 1;
                int k = 0;
                
                // get the number k
                while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                    k = k + (stack.pop() - '0') * base;
                    base *= 10;
                }
                
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString.get(j));
                    }
                    k--;
                }
            }
            
            // push the current character to stack
            else {
                stack.push(s.charAt(i));
            }
        }      
        
        // get the result from stack
        char[] result = new char[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        
        return new String(result);
    }
}

// Runtime: 1 ms, faster than 58.68% of Java online submissions for Decode String.
// Memory Usage: 37.3 MB, less than 35.13% of Java online submissions for Decode String.
// Time Complexity: O ((maxK^ countK) * n), where maxK is the maximum value of k, \countK is the count of nested k values 
// and n is the maximum length of encoded string. 
// Example, for s = 20[a10[bc]], \maxK is 20, countK is 22 as there are 2 nested k values (20 and 10) . 
// Also, there are 2 encoded strings a and bc with maximum length of encoded string ,n as 2
// Space Complexity: O(sum(maxK^ countK) * n)), where maxK is the maximum value of k, countK is the count of nested k values 
// and n is the maximum length of encoded string.