/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> output;
        // cout << customfunction.f(1, 1);
        
        // for x 
        for (int x = 1; x <= 1000; ++x) {
            for (int y = 1; y <= 1000; ++y) {
                int value = customfunction.f(x, y);
                if (value == z) {
                    output.push_back({x, y});
                }
                else if (value > z) {
                    break;
                }
            }
        }
        
        return output;
    }
};

// Runtime: 4 ms, faster than 71.43% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
// time complexity: O(1000 * 1000)
// space complexity: O(1)