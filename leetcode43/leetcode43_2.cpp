class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.length() > num2.length()) {
            swap(num1, num2);
        }
        
        int m = num1.length(), n = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<int> ans(m + n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for (int i = 0; i < m + n; i++) {
            if (ans[i] >= 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }
        
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        string output;
        for (int i: ans) {
            output += i + '0';
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 95.08% of C++ online submissions for Multiply Strings.
// Memory Usage: 8.7 MB, less than 87.18% of C++ online submissions for Multiply Strings.
// time complexity: O(m * n)
// space complexity: O(m + n)