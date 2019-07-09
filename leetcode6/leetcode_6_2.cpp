class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
// Runtime: 4 ms, faster than 99.56% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 10.4 MB, less than 56.34% of C++ online submissions for ZigZag Conversion.
// Time Complexity: O(n), where n == len(s). Each index is visited once.
// Space Complexity: O(n). For the cpp implementation, O(1) if return string is not considered extra space.