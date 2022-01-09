class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int r = 0; r < n; ++r)
        {
            unordered_set<int> row;
            unordered_set<int> col;
            for (int c = 0; c < n; ++c)
            {
                row.insert(matrix[r][c]);
                col.insert(matrix[c][r]);
            }
            if (row.size() < n || col.size() < n)
            {
                return false;
            }
        }
        return true;
    }
};

// Runtime: 567 ms, faster than 5.88% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// Memory Usage: 90.9 MB, less than 5.88% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// time complexity: O(n)
// space complexity: O(log n)
// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/discuss/1677019/JavaPython-3-Use-HashSet-to-check-each-row-column.