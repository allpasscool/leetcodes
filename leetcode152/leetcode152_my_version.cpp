class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int sub_max = INT_MIN, max_production = INT_MIN;
        int production = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            production *= nums[i];
            
            if (nums[i] > 0) {
                if (production > 0)
                    sub_max = max(sub_max, production);
                else if (production < 0)
                    sub_max = sub_max <= 0 ? nums[i] : sub_max * nums[i];
            }
            else if (nums[i] < 0) {
                if (production > 0)
                    sub_max = max(sub_max, production);
                if (production < 0) {
                    max_production = max(sub_max, max_production);
                    sub_max = nums[i];
                }
            }
            else if (nums[i] == 0) {
                max_production = max(max_production, sub_max);
                sub_max = 0;
                production = 1;
            }
        }
        
        max_production = max(max_production, sub_max);
        production = 1;
        sub_max = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            production *= nums[i];
            
            if (nums[i] > 0) {
                if (production > 0)
                    sub_max = max(sub_max, production);
                else if (production < 0)
                    sub_max = sub_max <= 0 ? nums[i] : sub_max * nums[i];
            }
            else if (nums[i] < 0) {
                if (production > 0)
                    sub_max = max(sub_max, production);
                if (production < 0) {
                    max_production = max(sub_max, max_production);
                    sub_max = nums[i];
                }
            }
            else if (nums[i] == 0) {
                max_production = max(max_production, sub_max);
                sub_max = 0;
                production = 1;
            }
        }
        
        return max(sub_max, max_production);
    }
};

// Runtime: 4 ms, faster than 88.48% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 9.1 MB, less than 82.50% of C++ online submissions for Maximum Product Subarray.
// time complexity: O(n)
// space complexity: O(1)