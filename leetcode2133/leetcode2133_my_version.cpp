class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<bool>> row(n, vector<bool>(n, false)); // row number
        vector<vector<bool>> col(n, vector<bool>(n, false)); // col number

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i][matrix[i][j] - 1] || col[j][matrix[i][j] - 1])
                    return false;

                row[i][matrix[i][j] - 1] = true;
                col[j][matrix[i][j] - 1] = true;
            }
        }

        return true;
    }
};

// Runtime: 108 ms, faster than 70.59% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// Memory Usage: 36.8 MB, less than 52.94% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// time complexity: O(n)
// space complexity: O(n^2)