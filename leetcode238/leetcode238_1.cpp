class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_production(n, 0);
        vector<int> right_production(n, 0);
        
        int production = 1;
        
        // left production, doesn't include nums[i]
        for (int i = 0; i < n; ++i) {
            left_production[i] = production;
            production *= nums[i];
        }
        
        production = 1;
        
        //right production
        for (int i = n - 1; i >= 0; i--) {
            right_production[i] = production;
            production *= nums[i];
        }
        
        // output
        vector<int> output(n, 0);
        for (int i = 0; i < n; ++i) {
            output[i] = left_production[i] * right_production[i];
        }
        
        return output;
    }
};

// Runtime: 44 ms, faster than 38.64% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 12.9 MB, less than 34.85% of C++ online submissions for Product of Array Except Self.
// time complexity: O(n)
// space complexity: O(n)