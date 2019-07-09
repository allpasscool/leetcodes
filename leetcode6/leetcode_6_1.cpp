class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
// Runtime: 8 ms, faster than 95.63% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 12.6 MB, less than 40.08% of C++ online submissions for ZigZag Conversion.
// Time Complexity: O(n), where n == len(s)
// Space Complexity: O(n)