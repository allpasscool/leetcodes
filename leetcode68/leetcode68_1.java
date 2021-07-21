class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        
        for (int i = 0, j, len; i < words.length; i += j) {
            // check word to add into cur line until can't add any more
            for (j = len = 0; i + j < words.length && len + words[i + j].length() <= maxWidth - j; ++j) {
                len += words[i + j].length();
            }
            
            StringBuilder curLine = new StringBuilder(words[i]);
            
            for (int k = 0; k < j - 1; ++k) {
                // last line
                if (i + j >= words.length) {
                    curLine.append(' ');
                }
                else {
                    // add spaces
                    // check whether add extra space
                    for (int counter = 0; 
                         counter < (maxWidth - len) / (j - 1) 
                         + ((k < (maxWidth - len) % (j - 1)) ? 1 : 0); counter++)
                    {
                        curLine.append(' ');
                    }
                }
                curLine.append(words[i + k + 1]);
            }
            
            // spaces reamin? only for last line case
            int spaces = maxWidth - curLine.length();
            for (int counter = 0; counter < spaces; counter++)
            {
                curLine.append(' ');
            }
            
            ans.add(curLine.toString());
        }
        
        return ans;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Text Justification.
// Memory Usage: 37.6 MB, less than 38.46% of Java online submissions for Text Justification.
// time complexity: O(n)
// space complexity: O(1)
// https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c%2B%2B-solution-less-than-20-lines