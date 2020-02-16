class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        int row = 0, col = n - 1;
        
        while (row < m) {
           while (col >= 0 && grid[row][col] < 0) {
               col--;
           }
            
            count += n - col - 1;
            ++row;
        }
        
        return count;
    }
};


// Runtime: 16 ms, faster than 88.89% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
// time complexity: O(n + m)
// space complexity: O(1)
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510217/C%2B%2B-Three-Methods