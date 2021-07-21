class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ansStr = new ArrayList<>();
        Queue<String> curLine = new LinkedList<>();
        // curCount means length of current line
        int curCount = 0;
        
        // each line
        for (String w : words)
        {
            // exceed maxWidth
            // words + spaces + new word > maxWidth
            if (curCount + curLine.size() + w.length() > maxWidth)
            {
                appendAns(curLine, ansStr, maxWidth, curCount);
                curCount = 0;
            }
            
            curCount += w.length();
            curLine.add(w);
        }
        
        // last Line
        if (!curLine.isEmpty())
        {
            appendAnsLastLine(curLine, ansStr, maxWidth, curCount);
        }
        
        return ansStr;
    }
    
    private void appendAns(Queue<String> curLine, List<String> ansStr, int maxWidth, int curCount)
    {
        // special case, when single word is as long as maxWidth
        if (curLine.size() == 1 && curLine.peek().length() == maxWidth)
        {
            ansStr.add(curLine.poll());
            return;
        }
        else if (curLine.size() == 1)
        {
            curLine.add(new String(" "));
            curCount += 1;
        }
        
        StringBuilder line = new StringBuilder();
        int spaces = maxWidth - curCount;
        int eachSpaces;

        while (!curLine.isEmpty())
        {
            line.append(curLine.poll());
            if (curLine.isEmpty())
                break;
            
            // with extraSpace than average
            if (spaces % (curLine.size()) != 0)
            {
                eachSpaces = spaces / curLine.size() + 1;
            }
            // only average spaces
            else
            {
                eachSpaces = spaces / curLine.size();
            }
            
            // add spaces
            for (int i = 0; i < eachSpaces; i++)
            {
                line.append(' ');
            }
            // remain spaces
            spaces = spaces - eachSpaces;
        }
        
        ansStr.add(line.toString());
    }
    
    private void appendAnsLastLine(Queue<String> curLine, List<String> ansStr, int maxWidth, int curCount)
    {    
        StringBuilder line = new StringBuilder();
        // append first word
        line.append(curLine.poll());
        
        while (!curLine.isEmpty())
        {
            line.append(' ');
            curCount++;
            line.append(curLine.poll());
        }
        
        while (curCount < maxWidth)
        {
            line.append(' ');
            curCount++;
        }
        
        ansStr.add(line.toString());
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Text Justification.
// Memory Usage: 37.8 MB, less than 30.92% of Java online submissions for Text Justification.
// time complexity: O(n)
// space complexity: O(1)