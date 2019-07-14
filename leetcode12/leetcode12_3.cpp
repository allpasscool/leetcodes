class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return M[num / 1000] + C[num / 100 % 10] + X[num / 10 % 10] + I[num % 10];
    }
};
// Runtime: 12 ms, faster than 66.04% of C++ online submissions for Integer to Roman.
// Memory Usage: 8.4 MB, less than 74.33% of C++ online submissions for Integer to Roman.
// time complexity: O(1)
// space complexity: O(1)