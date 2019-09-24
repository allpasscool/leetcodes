class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        ++digits[n - 1];
        
        if (digits[n - 1] < 10) {
            return digits;
        }
        
        for (int i = n - 1; i >= 1; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                ++digits[i - 1];
            }
            else {
                return digits;
            }
        }
        
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};

// Runtime: 4 ms, faster than 65.22% of C++ online submissions for Plus One.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Plus One.
// time complexity: O(n)
// space ocmplexity: O(1)