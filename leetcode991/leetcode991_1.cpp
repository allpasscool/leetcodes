class Solution {
public:
    int brokenCalc(int X, int Y) {
        int output = 0;
        
        while (Y > X) {
            ++output;
            if (Y % 2 == 1)
                ++Y;
            else
                Y /= 2;
        }
        
        return output + (X - Y);
    }
};

// Runtime: 4 ms, faster than 56.45% of C++ online submissions for Broken Calculator.
// Memory Usage: 8.3 MB, less than 60.00% of C++ online submissions for Broken Calculator.
// time complexity: O(log Y)
// space complexity: O(1)