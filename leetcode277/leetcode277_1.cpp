class Solution {
public:
    int calculate(string s) {
        stringstream ss("+" + s); // string becomes +s...
        char op;
        int n, last, ans = 0;
        
        while (ss >> op >> n) {
            if (op == '+' || op == '-') {
                n = op == '+' ? n : -n;
                ans += n;
            }
            else {
                n = op == '*' ? last * n : last / n;
                ans = ans - last + n; // simulate a stack by recovering last values
            }
            last = n;
        }
        
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(1)
// Runtime: 20 ms, faster than 92.55% of C++ online submissions for Basic Calculator II.
// Memory Usage: 8.5 MB, less than 58.47% of C++ online submissions for Basic Calculator II.

// https://leetcode.com/problems/basic-calculator-ii/discuss/63004/17-lines-C%2B%2B-easy-20-ms
// // O(N) time O(1) space
// int calculate(string s) {
//         stringstream ss("+" + s);
//         char op;
//         int n, last, ans = 0;
//         while (ss >> op >> n) {
//             if (op == '+' || op == '-') {
//                 n = op == '+' ? n : -n;
//                 ans += n;
//             } else {
//                 n = op == '*' ? last * n : last / n;
//                 ans = ans - last + n; // simulate a stack by recovering last values
//             }
//             last = n;
//         }
//         return ans;
// }