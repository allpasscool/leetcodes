class Solution {
public:
    int calculate(string s) {
        stack<long long> nums, operators;
        // operators top store the operation for nums.top() and current result
        long long num = 0;
        long long result = 0;
        long long sign = 1;
        
        for (char c: s) {
            // 23
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            // +, -, (, ), ' '
            else {
                result += sign * num;
                num = 0;
                
                // everytime meets an operator, sum up previous number
                // sign is the sign for next num
                if (c == '+')
                    sign = 1;
                else if (c == '-')
                    sign = -1;
                else if (c == '(') {
                    // ...(1+3-(..xx..)+...)... before go into cur (..xx..),
                    // record the forefront result (in this case it is 1+3 )
                    // into nums array 
                    nums.push(result);
                    // record cur (..xx..) sign
                    operators.push(sign);
                    result = 0;
                    sign = 1;
                }
                else if (c == ')' && !operators.empty()) {
                    result = operators.top() * result + nums.top();
                    operators.pop();
                    nums.pop();
                }
            }
        }
        
        // For the last one operation. consider the case:  1+2+3
        result += sign * num;
        return result;
    }
};
// int calculate(string s) {
//     stack <long long> nums, ops;
//     long long num = 0;
//     long long rst = 0;
//     long long sign = 1;
//     for (char c : s) { 
//         if (isdigit(c)) {
//             num = num * 10 + c - '0';
//         }
//         else {
//             rst += sign * num;
//             num = 0;
//             if (c == '+') sign = 1;
//             if (c == '-') sign = -1;
//             if (c == '(') {
//                 nums.push(rst);
//                 ops.push(sign);
//                 rst = 0;
//                 sign = 1;
//             }
//             if (c == ')' && ops.size()) {
//                 rst = ops.top() * rst + nums.top();
//                 ops.pop(); nums.pop();
//             }
//         }
//     }
//     rst += sign * num;
//     return rst;
// }

// Runtime: 12 ms, faster than 89.19% of C++ online submissions for Basic Calculator.
// Memory Usage: 10.5 MB, less than 61.90% of C++ online submissions for Basic Calculator.
// time complexity: O(n), n is the lenght of string, 
// space complexity: O(n)