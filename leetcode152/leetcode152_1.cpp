class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // sub_max and sub_min ends up with multiple the nums[i]
        int sub_max = nums[0], sub_min = nums[0], max_production = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0)
                swap(sub_max, sub_min);
            
            sub_max = max(nums[i], sub_max * nums[i]);
            sub_min = min(nums[i], sub_min * nums[i]);
            
            max_production = max(sub_max, max_production);
        }
        
        return max_production;
    }
};

// Runtime: 4 ms, faster than 88.48% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 9.1 MB, less than 85.00% of C++ online submissions for Maximum Product Subarray.
// time complexity: O(n)
// space complexity: O(1)