class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int directions = 0;
        vector<char> dirs = {'N', 'E', 'S', 'S'};
        int posY = 0, posX = 0;

        for (char &c : instructions)
        {
            if (c == 'R')
                directions = (directions + 1) % 4;
            else if (c == 'L')
                directions = (directions - 1 + 4) % 4;
            else
            {
                if (directions == 0)
                    posY++;
                else if (directions == 2)
                    posY--;
                else if (directions == 1)
                    posX++;
                else
                    posX--;
            }
        }

        if (directions != 0)
            return true;
        else if (directions == 0 && posY == 0 && posX == 0)
            return true;
        else
            return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
// Memory Usage: 6 MB, less than 79.45% of C++ online submissions for Robot Bounded In Circle.
// time complexity: O(n)
// space complexity: O(1)