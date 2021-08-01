// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
// Memory Usage: 6.1 MB, less than 77.30% of C++ online submissions for Robot Bounded In Circle.
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int x = 0, y = 0;

        for (char ins : instructions)
        {
            switch (ins)
            {
            case 'G':
                x += dirs[dir].first;
                y += dirs[dir].second;
                break;
            case 'L':
                dir = (dir + 1) % 4;
                break;
            case 'R':
                dir = (dir + 4 - 1) % 4;
            }
        }

        return (x == 0 && y == 0) || (dir != 0);
    }
};