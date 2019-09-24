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
            digits[0] = 1;
            // digits.insert(digits.begin(), 1);
            digits.push_back(0);
        }
        
        return digits;
    }
};