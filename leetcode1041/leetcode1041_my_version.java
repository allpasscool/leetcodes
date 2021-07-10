class Solution {
    public boolean isRobotBounded(String instructions) {
        int dir = 0;
        int posX = 0, posY = 0;
        
        for (char ins: instructions.toCharArray())
        {
            if (ins == 'L')
            {
                dir--;
            }
            else if (ins == 'R')
            {
                dir++;
            }
            
            if (ins == 'G')
            {
                // go up
                if (dir % 4 == 0)
                {
                    posY++;
                }
                // go right
                else if (dir % 4 == 1 || dir % 4 == -3)
                {
                    posX++;
                }
                // go down
                else if (dir % 4 == 2 || dir % 4 == -2)
                {
                    posY--;
                }
                // go left
                else if (dir % 4 == 3 || dir % 4 == -1)
                {
                    posX--;
                }
            }
        }
        
        // after one round, still in Origin
        if (posX == 0 && posY == 0)
        {
            return true;
        }
        
        // if you have moved and only moving forward
        if (dir % 4 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Robot Bounded In Circle.
// Memory Usage: 37 MB, less than 70.35% of Java online submissions for Robot Bounded In Circle.
// time complexity: O(n)
// space complexity: O(1)