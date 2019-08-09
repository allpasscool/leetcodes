class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int n1 = num1.length(), n2 = num2.length();
        int ans[n1 + n2] = {0};
        
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                //result of multiplication
                int mul = (num1[i] - '0') * (num2[j] - '0');
                //sum of this position
                int sum = mul + ans[i + j + 1];
                //update ans[i + j + 1]
                ans[i + j + 1] = sum % 10;
                //update ans[i + j]
                ans[i + j] += sum / 10; 
            }
        }
        
        string output = "";
        
        for (int i = 0; i < n1 + n2; i++) {
            //leading 0?
            if (i == 0 && ans[i] == 0) {
                continue;
            }
            
            output.append(1, (char)(ans[i] + '0'));
        }
        
        return output;
    }
};
// Runtime: 8 ms, faster than 65.95% of C++ online submissions for Multiply Strings.
// Memory Usage: 8.8 MB, less than 71.79% of C++ online submissions for Multiply Strings.
// time complexity: O(m * n), m is length of num1, n is length of num2
// space complexity: O(m + n)