class Solution
{
public:
    bool checkValid(vector<vector<int>> &m)
    {
        int n = m.size();
        for (int i = 0; i < m.size(); ++i)
        {
            bitset<101> row, col;
            for (int j = 0; j < m.size(); ++j)
                row[m[i][j]] = col[m[j][i]] = true;
            if (min(row.count(), col.count()) < m.size())
                return false;
        }
        return true;
    }
};

// Runtime: 218 ms, faster than 58.82% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// Memory Usage: 34.7 MB, less than 58.82% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// time complexity: O(n)
// space compexlity: O(log n)
https: //leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/discuss/1676893/Bitset